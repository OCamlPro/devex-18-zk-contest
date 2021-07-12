#include <stdlib.h>
#include <iostream>

#include <nil/crypto3/zk/components/blueprint.hpp>
#include <nil/crypto3/zk/snark/algorithms/generate.hpp>
#include <nil/crypto3/zk/snark/algorithms/verify.hpp>
#include <nil/crypto3/zk/snark/algorithms/prove.hpp>

#include <nil/crypto3/zk/snark/schemes/ppzksnark/r1cs_gg_ppzksnark.hpp>

#include <nil/crypto3/algebra/curves/bls12.hpp>
#include <nil/crypto3/algebra/fields/bls12/base_field.hpp>
#include <nil/crypto3/algebra/fields/bls12/scalar_field.hpp>
#include <nil/crypto3/algebra/fields/arithmetic_params/bls12.hpp>
#include <nil/crypto3/algebra/curves/params/multiexp/bls12.hpp>
#include <nil/crypto3/algebra/curves/params/wnaf/bls12.hpp>

#include <nil/crypto3/algebra/fields/detail/element/fp.hpp>
#include <nil/crypto3/algebra/fields/detail/element/fp2.hpp>

#include <nil/marshalling/status_type.hpp>

// #include "sudoku.hpp"
// #include "picosha2.hpp"
#include <fstream>

using namespace nil::crypto3;
using namespace nil::crypto3::zk;
using namespace nil::crypto3::zk::components;
using namespace nil::crypto3::algebra;
using namespace nil::crypto3::zk::snark ;

typedef algebra::curves::bls12<381> curve_type;
typedef typename curve_type::scalar_field_type field_type;
typedef zk::snark::r1cs_gg_ppzksnark<curve_type> scheme_type;



// must be done here, after definition of curve_type and field_type
#include "utils.hpp"

std::vector<int> read_input(std::string filename){
  std::vector<int> sudoku;
  std::ifstream inFile;
  inFile.open(filename.c_str());
  if (inFile.is_open())
    {
      for (int i = 0; i < 81; i++)
        {
	  char temp;
	  inFile >> temp;
	  sudoku.push_back((int)temp - (int)48); //convert char to int
	  std::cout << sudoku[i] << " ";
        }
      std::cout << std::endl;

      inFile.close();
    }
    else { //Error message
      std::cerr << "Can't find input file " << filename << std::endl;
    }
    return sudoku;
}


std::vector<int> input_instance(std::string filename){
  std::vector<int> sudoku = read_input(filename);
  return sudoku;
}

std::vector<int> input_solved(std::string filename){
  std::vector<int> sudoku = read_input(filename);
  return sudoku;
}

//void build_blueprint(blueprint<field_type>  &bp, bool with_instance, std::vector<int> sudoku_instance, std::vector<int> sudoku_solution){


int generate_keys(){

  using curve_type = curves::bls12<381>;
  using field_type = typename curve_type::scalar_field_type;

  std::vector<int> empty_instance;
  blueprint<field_type> bp;

  bool with_instance = false ;
  std::vector<int> sudoku_instance = empty_instance ;
  std::vector<int> sudoku_solution = empty_instance ;
#include "build_blueprint.hpp"

  std::cerr << "(1)" << std::endl ;
  
  const r1cs_constraint_system<field_type> constraint_system = bp.get_constraint_system();
  std::cerr << "(1)" << std::endl ;

  const typename r1cs_gg_ppzksnark<curve_type>::keypair_type keypair = generate<r1cs_gg_ppzksnark<curve_type>>(constraint_system);
  std::cerr << "(1)" << std::endl ;

    // prepare proving key for marshalling
  std::vector<std::uint8_t> proving_key_byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(keypair.first);
  std::cerr << "(1)" << std::endl ;

  boost::filesystem::ofstream poutf1("sudoku_proving_key.bin");
  for (const auto &v : proving_key_byteblob) {
    poutf1 << v;
  }
  poutf1.close();
  std::cerr << "(1)" << std::endl ;

  // preparing verification key for marshalling
  std::vector<std::uint8_t> verification_key_byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(keypair.second);

  boost::filesystem::ofstream poutf2("sudoku_verification_key.bin");
  for (const auto &v : verification_key_byteblob) {
    poutf2 << v;
  }
  poutf2.close();


  return 0;
}


typename scheme_type::proving_key_type fetch_proving_key(){
  std::vector<uint8_t> proving_key_byteblob = read_vector_from_disk("sudoku_proving_key.bin");

  // this line is necessary but I don't understand it (I guess it's a
  // default value?)
  nil::marshalling::status_type provingProcessingStatus = nil::marshalling::status_type::success;

  typename scheme_type::proving_key_type proving_key =
    nil::marshalling::verifier_input_deserializer_tvm<scheme_type>::proving_key_process
    (
     proving_key_byteblob.cbegin(),
     proving_key_byteblob.cend(),
     provingProcessingStatus);

  return proving_key;
}

typename scheme_type::verification_key_type fetch_verification_key(){
  std::vector<uint8_t> verification_key_byteblob = read_vector_from_disk("sudoku_verification_key.bin");

  // this line is necessary but I don't understand it
  nil::marshalling::status_type processingStatus = nil::marshalling::status_type::success;

  typename scheme_type::verification_key_type verification_key =
    nil::marshalling::verifier_input_deserializer_tvm<scheme_type>::verification_key_process
    (
     verification_key_byteblob.cbegin(),
     verification_key_byteblob.cend(),
     processingStatus);

  return verification_key;
}


void prove(std::vector<int> sudoku_instance, std::vector<int> sudoku_solution){

  typename scheme_type::proving_key_type proving_key =
    fetch_proving_key();
  typename scheme_type::verification_key_type verification_key =
    fetch_verification_key();

  using curve_type = curves::bls12<381>;
  using field_type = typename curve_type::scalar_field_type;

  blueprint<field_type> bp;

  bool with_instance = true ;
#include "build_blueprint.hpp"

  r1cs_variable_assignment<field_type> full_variable_assignment = bp.primary_input();

  std::cout << "coucou3" << std::endl;
  //std::cout << bp.auxiliary_input().begin() << std::endl;
  std::cout << "coucou4" << std::endl;
  r1cs_auxiliary_input<field_type> aux = bp.auxiliary_input();
  full_variable_assignment.insert(
				  full_variable_assignment.end(),
				  aux.begin(),
				  aux.end());
  std::cout << "coucou4" << std::endl;
  const r1cs_constraint_system<field_type> constraints = bp.get_constraint_system();
  std::cout << "coucou5" << std::endl;
  for (std::size_t c = 0; c < constraints.num_constraints(); ++c) {
    field_type::value_type ares =
      constraints.constraints[c].a.evaluate(full_variable_assignment);
    field_type::value_type bres =
      constraints.constraints[c].b.evaluate(full_variable_assignment);
    field_type::value_type cres =
      constraints.constraints[c].c.evaluate(full_variable_assignment);

    if(ares * bres == cres){
      std::cout << "equal" << std::endl;
    }
    if(!(ares * bres == cres)){
      std::cout << "not equal" << std::endl;
    }
  }

  const r1cs_constraint_system<field_type> constraint_system = bp.get_constraint_system();

   const typename r1cs_gg_ppzksnark<curve_type>::proof_type proof = prove<r1cs_gg_ppzksnark<curve_type>>(proving_key, bp.primary_input(), bp.auxiliary_input());

    bool verified = verify<r1cs_gg_ppzksnark<curve_type>>(verification_key, bp.primary_input(), proof);

      std::vector<std::uint8_t> verification_key_byteblob = nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(verification_key);
  std::vector<std::uint8_t> primary_input_byteblob = nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(bp.primary_input());
  std::vector<std::uint8_t> proof_byteblob = nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(proof);

  {
    std::vector<std::uint8_t> byteblob;

    append_to_byteblob( byteblob, proof_byteblob ) ;
    append_to_byteblob( byteblob, primary_input_byteblob ) ;
    append_to_byteblob( byteblob, verification_key_byteblob ) ;

    binfile_of_byteblob( "big_proof.bin", byteblob );
    hexfile_of_byteblob( "big_proof.hex", byteblob );
  }


    std::cout << "Number of R1CS constraints: " << constraint_system.num_constraints() << std::endl;
    std::cout << "Verification status: " << verified << std::endl;

    binfile_of_byteblob( "proof.bin", proof_byteblob );
    hexfile_of_byteblob( "proof.hex", proof_byteblob );

    return;

}


 
