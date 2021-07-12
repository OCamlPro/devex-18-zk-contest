
#include <sys/stat.h>

inline bool file_exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

template <typename InIter>
void output_hex(InIter first, InIter last, std::ostream& os) {
    os.setf(std::ios::hex, std::ios::basefield);
    while (first != last) {
        os.width(2);
        os.fill('0');
        os << static_cast<unsigned int>(*first);
        ++first;
    }
    os.setf(std::ios::dec, std::ios::basefield);
}

template <typename InIter>
void bytes_to_hex_string(InIter first, InIter last, std::string& hex_str) {
    std::ostringstream oss;
    output_hex(first, last, oss);
    hex_str.assign(oss.str());
}

template <typename InContainer>
void bytes_to_hex_string(const InContainer& bytes, std::string& hex_str) {
    bytes_to_hex_string(bytes.begin(), bytes.end(), hex_str);
}

template <typename InIter>
std::string bytes_to_hex_string(InIter first, InIter last) {
    std::string hex_str;
    bytes_to_hex_string(first, last, hex_str);
    return hex_str;
}

template <typename InContainer>
std::string bytes_to_hex_string(const InContainer& bytes) {
    std::string hex_str;
    bytes_to_hex_string(bytes, hex_str);
    return hex_str;
}

std::vector<uint8_t> read_vector_from_disk(std::string file)
{  
  std::cerr << "Loading from '" << file << "." << std::endl ;
  if( ! file_exists(file) ){
    std::cerr << "Error: file does not exist" << std::endl ;
    exit(2) ;
  }
  
  std::ifstream instream(file, std::ios::in | std::ios::binary);
  std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());
  return data;
}


void append_to_byteblob( std::vector<std::uint8_t> &byteblob, std::vector<std::uint8_t> bytes)
{
  byteblob.insert (byteblob.end(), bytes.begin(), bytes.end());
}

void hexfile_of_byteblob( std::string file,  std::vector<std::uint8_t> byteblob ){
  std::string hex_str = bytes_to_hex_string(byteblob.begin(), byteblob.end());
  boost::filesystem::ofstream poutf( file );
  poutf << hex_str << std::endl;
  poutf.close();
}

void binfile_of_byteblob( std::string file,  std::vector<std::uint8_t> byteblob ){
  boost::filesystem::ofstream poutf( file );
  for (const auto &v : byteblob) {
    poutf << v;
  }
  poutf.close();
  std::cerr << "File '" << file << "' generated." << std::endl ;
  file.append(".hex");
  hexfile_of_byteblob( file, byteblob );
}

int int_of_hexchar(char input)
{
  if(input >= '0' && input <= '9')
    return input - '0';
  if(input >= 'A' && input <= 'F')
    return input - 'A' + 10;
  if(input >= 'a' && input <= 'f')
    return input - 'a' + 10;
  throw std::invalid_argument("Invalid input string");
}


typename scheme_type::proving_key_type load_proving_key( std::string file ){
  std::vector<uint8_t> byteblob = read_vector_from_disk( file ) ;

  // this line is necessary but I don't understand it
  nil::marshalling::status_type status =
    nil::marshalling::status_type::success;

  typename scheme_type::proving_key_type v =
    nil::marshalling::verifier_input_deserializer_tvm<scheme_type>::proving_key_process
    ( byteblob.cbegin(), byteblob.cend(), status);

  return v;
}

typename scheme_type::verification_key_type
  load_verification_key( std::string file ){
  std::vector<uint8_t> byteblob = read_vector_from_disk( file ) ;

  // this line is necessary but I don't understand it
  nil::marshalling::status_type status =
    nil::marshalling::status_type::success;

  typename scheme_type::verification_key_type v =
    nil::marshalling::verifier_input_deserializer_tvm<scheme_type>::verification_key_process
    ( byteblob.cbegin(), byteblob.cend(), status);

  return v;
}

typename scheme_type::primary_input_type
  load_primary_input( std::string file ){
  std::vector<uint8_t> byteblob = read_vector_from_disk( file ) ;

  // this line is necessary but I don't understand it
  nil::marshalling::status_type status =
    nil::marshalling::status_type::success;

  typename scheme_type::primary_input_type v =
    nil::marshalling::verifier_input_deserializer_tvm<scheme_type>::primary_input_process
    ( byteblob.cbegin(), byteblob.cend(), status);

  return v;
}

void save_proving_key( std::string file,
                       typename scheme_type::proving_key_type v ){
  std::vector<std::uint8_t> byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process( v );
  binfile_of_byteblob( file, byteblob );
}

void save_verification_key( std::string file,
                       typename scheme_type::verification_key_type v ){
  std::vector<std::uint8_t> byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process( v );
  binfile_of_byteblob( file, byteblob );
}

void save_primary_input( std::string file,
                         typename scheme_type::primary_input_type v ){
  std::vector<std::uint8_t> byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process( v );
  binfile_of_byteblob( file, byteblob );
}

void save_auxiliary_input( std::string file,
                         typename scheme_type::auxiliary_input_type v ){
  std::vector<std::uint8_t> byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process( v );
  binfile_of_byteblob( file, byteblob );
}

void save_proof( std::string file,
                 typename r1cs_gg_ppzksnark<curve_type>::proof_type v ){
  std::vector<std::uint8_t> byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process( v );
  binfile_of_byteblob( file, byteblob );
}

void save_big_proof( std::string file,
                     typename r1cs_gg_ppzksnark<curve_type>::proof_type proof,
                     typename scheme_type::primary_input_type primary_input,
                     typename scheme_type::verification_key_type vk
                     ){
  std::vector<std::uint8_t> verification_key_byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process( vk ) ;
  std::vector<std::uint8_t> proof_byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process( proof);
  std::vector<std::uint8_t> primary_input_byteblob =
    nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(
                                                                          primary_input );

 std::vector<std::uint8_t> byteblob;

 append_to_byteblob( byteblob, proof_byteblob ) ;
 append_to_byteblob( byteblob, primary_input_byteblob ) ;
 append_to_byteblob( byteblob, verification_key_byteblob ) ;
 
 binfile_of_byteblob( file, byteblob );
}
