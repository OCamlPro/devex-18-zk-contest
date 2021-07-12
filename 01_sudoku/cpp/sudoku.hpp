//---------------------------------------------------------------------------//
// Copyright (c) 2018-2021 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020-2021 Nikita Kaskov <nbering@nil.foundation>
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_BLUEPRINT_SUDOKU_TEST_COMPONENT_HPP
#define CRYPTO3_BLUEPRINT_SUDOKU_TEST_COMPONENT_HPP

#include <nil/crypto3/zk/components/component.hpp>

#include <nil/crypto3/zk/components/blueprint.hpp>
#include <nil/crypto3/zk/components/blueprint_variable.hpp>
// #include <nil/crypto3/zk/snark/components/basic_components.hpp>

#include <nil/crypto3/zk/snark/relations/constraint_satisfaction_problems/r1cs.hpp>

using namespace nil::crypto3;
using namespace nil::crypto3::zk;
using namespace nil::crypto3::zk::components;
using namespace nil::crypto3::algebra;
using namespace nil::crypto3::zk::snark ;

template<typename FieldType>
class test_component : public nil::crypto3::zk::components::component<FieldType> {
    using field_type = FieldType;
    //private (intermediary) variables

    //blueprint_variable<field_type> sym_1;
    //blueprint_variable<field_type> y;
    //blueprint_variable<field_type> sym_2;
public:
    //public variables

    const blueprint_variable<field_type> free_x_0_0;
    const blueprint_variable<field_type> free_x_0_1;
    const blueprint_variable<field_type> free_x_0_2;
    const blueprint_variable<field_type> free_x_0_3;
    const blueprint_variable<field_type> free_x_0_4;
    const blueprint_variable<field_type> free_x_0_5;
    const blueprint_variable<field_type> free_x_0_6;
    const blueprint_variable<field_type> free_x_0_7;
    const blueprint_variable<field_type> free_x_0_8;
    const blueprint_variable<field_type> free_x_1_0;
    const blueprint_variable<field_type> free_x_1_1;
    const blueprint_variable<field_type> free_x_1_2;
    const blueprint_variable<field_type> free_x_1_3;
    const blueprint_variable<field_type> free_x_1_4;
    const blueprint_variable<field_type> free_x_1_5;
    const blueprint_variable<field_type> free_x_1_6;
    const blueprint_variable<field_type> free_x_1_7;
    const blueprint_variable<field_type> free_x_1_8;
    const blueprint_variable<field_type> free_x_2_0;
    const blueprint_variable<field_type> free_x_2_1;
    const blueprint_variable<field_type> free_x_2_2;
    const blueprint_variable<field_type> free_x_2_3;
    const blueprint_variable<field_type> free_x_2_4;
    const blueprint_variable<field_type> free_x_2_5;
    const blueprint_variable<field_type> free_x_2_6;
    const blueprint_variable<field_type> free_x_2_7;
    const blueprint_variable<field_type> free_x_2_8;
    const blueprint_variable<field_type> free_x_3_0;
    const blueprint_variable<field_type> free_x_3_1;
    const blueprint_variable<field_type> free_x_3_2;
    const blueprint_variable<field_type> free_x_3_3;
    const blueprint_variable<field_type> free_x_3_4;
    const blueprint_variable<field_type> free_x_3_5;
    const blueprint_variable<field_type> free_x_3_6;
    const blueprint_variable<field_type> free_x_3_7;
    const blueprint_variable<field_type> free_x_3_8;
    const blueprint_variable<field_type> free_x_4_0;
    const blueprint_variable<field_type> free_x_4_1;
    const blueprint_variable<field_type> free_x_4_2;
    const blueprint_variable<field_type> free_x_4_3;
    const blueprint_variable<field_type> free_x_4_4;
    const blueprint_variable<field_type> free_x_4_5;
    const blueprint_variable<field_type> free_x_4_6;
    const blueprint_variable<field_type> free_x_4_7;
    const blueprint_variable<field_type> free_x_4_8;
    const blueprint_variable<field_type> free_x_5_0;
    const blueprint_variable<field_type> free_x_5_1;
    const blueprint_variable<field_type> free_x_5_2;
    const blueprint_variable<field_type> free_x_5_3;
    const blueprint_variable<field_type> free_x_5_4;
    const blueprint_variable<field_type> free_x_5_5;
    const blueprint_variable<field_type> free_x_5_6;
    const blueprint_variable<field_type> free_x_5_7;
    const blueprint_variable<field_type> free_x_5_8;
    const blueprint_variable<field_type> free_x_6_0;
    const blueprint_variable<field_type> free_x_6_1;
    const blueprint_variable<field_type> free_x_6_2;
    const blueprint_variable<field_type> free_x_6_3;
    const blueprint_variable<field_type> free_x_6_4;
    const blueprint_variable<field_type> free_x_6_5;
    const blueprint_variable<field_type> free_x_6_6;
    const blueprint_variable<field_type> free_x_6_7;
    const blueprint_variable<field_type> free_x_6_8;
    const blueprint_variable<field_type> free_x_7_0;
    const blueprint_variable<field_type> free_x_7_1;
    const blueprint_variable<field_type> free_x_7_2;
    const blueprint_variable<field_type> free_x_7_3;
    const blueprint_variable<field_type> free_x_7_4;
    const blueprint_variable<field_type> free_x_7_5;
    const blueprint_variable<field_type> free_x_7_6;
    const blueprint_variable<field_type> free_x_7_7;
    const blueprint_variable<field_type> free_x_7_8;
    const blueprint_variable<field_type> free_x_8_0;
    const blueprint_variable<field_type> free_x_8_1;
    const blueprint_variable<field_type> free_x_8_2;
    const blueprint_variable<field_type> free_x_8_3;
    const blueprint_variable<field_type> free_x_8_4;
    const blueprint_variable<field_type> free_x_8_5;
    const blueprint_variable<field_type> free_x_8_6;
    const blueprint_variable<field_type> free_x_8_7;
    const blueprint_variable<field_type> free_x_8_8;
    const blueprint_variable<field_type> x_0_0;
    const blueprint_variable<field_type> x_0_1;
    const blueprint_variable<field_type> x_0_2;
    const blueprint_variable<field_type> x_0_3;
    const blueprint_variable<field_type> x_0_4;
    const blueprint_variable<field_type> x_0_5;
    const blueprint_variable<field_type> x_0_6;
    const blueprint_variable<field_type> x_0_7;
    const blueprint_variable<field_type> x_0_8;
    const blueprint_variable<field_type> x_1_0;
    const blueprint_variable<field_type> x_1_1;
    const blueprint_variable<field_type> x_1_2;
    const blueprint_variable<field_type> x_1_3;
    const blueprint_variable<field_type> x_1_4;
    const blueprint_variable<field_type> x_1_5;
    const blueprint_variable<field_type> x_1_6;
    const blueprint_variable<field_type> x_1_7;
    const blueprint_variable<field_type> x_1_8;
    const blueprint_variable<field_type> x_2_0;
    const blueprint_variable<field_type> x_2_1;
    const blueprint_variable<field_type> x_2_2;
    const blueprint_variable<field_type> x_2_3;
    const blueprint_variable<field_type> x_2_4;
    const blueprint_variable<field_type> x_2_5;
    const blueprint_variable<field_type> x_2_6;
    const blueprint_variable<field_type> x_2_7;
    const blueprint_variable<field_type> x_2_8;
    const blueprint_variable<field_type> x_3_0;
    const blueprint_variable<field_type> x_3_1;
    const blueprint_variable<field_type> x_3_2;
    const blueprint_variable<field_type> x_3_3;
    const blueprint_variable<field_type> x_3_4;
    const blueprint_variable<field_type> x_3_5;
    const blueprint_variable<field_type> x_3_6;
    const blueprint_variable<field_type> x_3_7;
    const blueprint_variable<field_type> x_3_8;
    const blueprint_variable<field_type> x_4_0;
    const blueprint_variable<field_type> x_4_1;
    const blueprint_variable<field_type> x_4_2;
    const blueprint_variable<field_type> x_4_3;
    const blueprint_variable<field_type> x_4_4;
    const blueprint_variable<field_type> x_4_5;
    const blueprint_variable<field_type> x_4_6;
    const blueprint_variable<field_type> x_4_7;
    const blueprint_variable<field_type> x_4_8;
    const blueprint_variable<field_type> x_5_0;
    const blueprint_variable<field_type> x_5_1;
    const blueprint_variable<field_type> x_5_2;
    const blueprint_variable<field_type> x_5_3;
    const blueprint_variable<field_type> x_5_4;
    const blueprint_variable<field_type> x_5_5;
    const blueprint_variable<field_type> x_5_6;
    const blueprint_variable<field_type> x_5_7;
    const blueprint_variable<field_type> x_5_8;
    const blueprint_variable<field_type> x_6_0;
    const blueprint_variable<field_type> x_6_1;
    const blueprint_variable<field_type> x_6_2;
    const blueprint_variable<field_type> x_6_3;
    const blueprint_variable<field_type> x_6_4;
    const blueprint_variable<field_type> x_6_5;
    const blueprint_variable<field_type> x_6_6;
    const blueprint_variable<field_type> x_6_7;
    const blueprint_variable<field_type> x_6_8;
    const blueprint_variable<field_type> x_7_0;
    const blueprint_variable<field_type> x_7_1;
    const blueprint_variable<field_type> x_7_2;
    const blueprint_variable<field_type> x_7_3;
    const blueprint_variable<field_type> x_7_4;
    const blueprint_variable<field_type> x_7_5;
    const blueprint_variable<field_type> x_7_6;
    const blueprint_variable<field_type> x_7_7;
    const blueprint_variable<field_type> x_7_8;
    const blueprint_variable<field_type> x_8_0;
    const blueprint_variable<field_type> x_8_1;
    const blueprint_variable<field_type> x_8_2;
    const blueprint_variable<field_type> x_8_3;
    const blueprint_variable<field_type> x_8_4;
    const blueprint_variable<field_type> x_8_5;
    const blueprint_variable<field_type> x_8_6;
    const blueprint_variable<field_type> x_8_7;
    const blueprint_variable<field_type> x_8_8;

    //const blueprint_variable<field_type> out;
    //const blueprint_variable<field_type> x;

    test_component(blueprint<field_type> &bp,
 const blueprint_variable<field_type> &free_x_0_0,
 const blueprint_variable<field_type> &free_x_0_1,
 const blueprint_variable<field_type> &free_x_0_2,
 const blueprint_variable<field_type> &free_x_0_3,
 const blueprint_variable<field_type> &free_x_0_4,
 const blueprint_variable<field_type> &free_x_0_5,
 const blueprint_variable<field_type> &free_x_0_6,
 const blueprint_variable<field_type> &free_x_0_7,
 const blueprint_variable<field_type> &free_x_0_8,
 const blueprint_variable<field_type> &free_x_1_0,
 const blueprint_variable<field_type> &free_x_1_1,
 const blueprint_variable<field_type> &free_x_1_2,
 const blueprint_variable<field_type> &free_x_1_3,
 const blueprint_variable<field_type> &free_x_1_4,
 const blueprint_variable<field_type> &free_x_1_5,
 const blueprint_variable<field_type> &free_x_1_6,
 const blueprint_variable<field_type> &free_x_1_7,
 const blueprint_variable<field_type> &free_x_1_8,
 const blueprint_variable<field_type> &free_x_2_0,
 const blueprint_variable<field_type> &free_x_2_1,
 const blueprint_variable<field_type> &free_x_2_2,
 const blueprint_variable<field_type> &free_x_2_3,
 const blueprint_variable<field_type> &free_x_2_4,
 const blueprint_variable<field_type> &free_x_2_5,
 const blueprint_variable<field_type> &free_x_2_6,
 const blueprint_variable<field_type> &free_x_2_7,
 const blueprint_variable<field_type> &free_x_2_8,
 const blueprint_variable<field_type> &free_x_3_0,
 const blueprint_variable<field_type> &free_x_3_1,
 const blueprint_variable<field_type> &free_x_3_2,
 const blueprint_variable<field_type> &free_x_3_3,
 const blueprint_variable<field_type> &free_x_3_4,
 const blueprint_variable<field_type> &free_x_3_5,
 const blueprint_variable<field_type> &free_x_3_6,
 const blueprint_variable<field_type> &free_x_3_7,
 const blueprint_variable<field_type> &free_x_3_8,
 const blueprint_variable<field_type> &free_x_4_0,
 const blueprint_variable<field_type> &free_x_4_1,
 const blueprint_variable<field_type> &free_x_4_2,
 const blueprint_variable<field_type> &free_x_4_3,
 const blueprint_variable<field_type> &free_x_4_4,
 const blueprint_variable<field_type> &free_x_4_5,
 const blueprint_variable<field_type> &free_x_4_6,
 const blueprint_variable<field_type> &free_x_4_7,
 const blueprint_variable<field_type> &free_x_4_8,
 const blueprint_variable<field_type> &free_x_5_0,
 const blueprint_variable<field_type> &free_x_5_1,
 const blueprint_variable<field_type> &free_x_5_2,
 const blueprint_variable<field_type> &free_x_5_3,
 const blueprint_variable<field_type> &free_x_5_4,
 const blueprint_variable<field_type> &free_x_5_5,
 const blueprint_variable<field_type> &free_x_5_6,
 const blueprint_variable<field_type> &free_x_5_7,
 const blueprint_variable<field_type> &free_x_5_8,
 const blueprint_variable<field_type> &free_x_6_0,
 const blueprint_variable<field_type> &free_x_6_1,
 const blueprint_variable<field_type> &free_x_6_2,
 const blueprint_variable<field_type> &free_x_6_3,
 const blueprint_variable<field_type> &free_x_6_4,
 const blueprint_variable<field_type> &free_x_6_5,
 const blueprint_variable<field_type> &free_x_6_6,
 const blueprint_variable<field_type> &free_x_6_7,
 const blueprint_variable<field_type> &free_x_6_8,
 const blueprint_variable<field_type> &free_x_7_0,
 const blueprint_variable<field_type> &free_x_7_1,
 const blueprint_variable<field_type> &free_x_7_2,
 const blueprint_variable<field_type> &free_x_7_3,
 const blueprint_variable<field_type> &free_x_7_4,
 const blueprint_variable<field_type> &free_x_7_5,
 const blueprint_variable<field_type> &free_x_7_6,
 const blueprint_variable<field_type> &free_x_7_7,
 const blueprint_variable<field_type> &free_x_7_8,
 const blueprint_variable<field_type> &free_x_8_0,
 const blueprint_variable<field_type> &free_x_8_1,
 const blueprint_variable<field_type> &free_x_8_2,
 const blueprint_variable<field_type> &free_x_8_3,
 const blueprint_variable<field_type> &free_x_8_4,
 const blueprint_variable<field_type> &free_x_8_5,
 const blueprint_variable<field_type> &free_x_8_6,
 const blueprint_variable<field_type> &free_x_8_7,
 const blueprint_variable<field_type> &free_x_8_8,
 const blueprint_variable<field_type> &x_0_0,
 const blueprint_variable<field_type> &x_0_1,
 const blueprint_variable<field_type> &x_0_2,
 const blueprint_variable<field_type> &x_0_3,
 const blueprint_variable<field_type> &x_0_4,
 const blueprint_variable<field_type> &x_0_5,
 const blueprint_variable<field_type> &x_0_6,
 const blueprint_variable<field_type> &x_0_7,
 const blueprint_variable<field_type> &x_0_8,
 const blueprint_variable<field_type> &x_1_0,
 const blueprint_variable<field_type> &x_1_1,
 const blueprint_variable<field_type> &x_1_2,
 const blueprint_variable<field_type> &x_1_3,
 const blueprint_variable<field_type> &x_1_4,
 const blueprint_variable<field_type> &x_1_5,
 const blueprint_variable<field_type> &x_1_6,
 const blueprint_variable<field_type> &x_1_7,
 const blueprint_variable<field_type> &x_1_8,
 const blueprint_variable<field_type> &x_2_0,
 const blueprint_variable<field_type> &x_2_1,
 const blueprint_variable<field_type> &x_2_2,
 const blueprint_variable<field_type> &x_2_3,
 const blueprint_variable<field_type> &x_2_4,
 const blueprint_variable<field_type> &x_2_5,
 const blueprint_variable<field_type> &x_2_6,
 const blueprint_variable<field_type> &x_2_7,
 const blueprint_variable<field_type> &x_2_8,
 const blueprint_variable<field_type> &x_3_0,
 const blueprint_variable<field_type> &x_3_1,
 const blueprint_variable<field_type> &x_3_2,
 const blueprint_variable<field_type> &x_3_3,
 const blueprint_variable<field_type> &x_3_4,
 const blueprint_variable<field_type> &x_3_5,
 const blueprint_variable<field_type> &x_3_6,
 const blueprint_variable<field_type> &x_3_7,
 const blueprint_variable<field_type> &x_3_8,
 const blueprint_variable<field_type> &x_4_0,
 const blueprint_variable<field_type> &x_4_1,
 const blueprint_variable<field_type> &x_4_2,
 const blueprint_variable<field_type> &x_4_3,
 const blueprint_variable<field_type> &x_4_4,
 const blueprint_variable<field_type> &x_4_5,
 const blueprint_variable<field_type> &x_4_6,
 const blueprint_variable<field_type> &x_4_7,
 const blueprint_variable<field_type> &x_4_8,
 const blueprint_variable<field_type> &x_5_0,
 const blueprint_variable<field_type> &x_5_1,
 const blueprint_variable<field_type> &x_5_2,
 const blueprint_variable<field_type> &x_5_3,
 const blueprint_variable<field_type> &x_5_4,
 const blueprint_variable<field_type> &x_5_5,
 const blueprint_variable<field_type> &x_5_6,
 const blueprint_variable<field_type> &x_5_7,
 const blueprint_variable<field_type> &x_5_8,
 const blueprint_variable<field_type> &x_6_0,
 const blueprint_variable<field_type> &x_6_1,
 const blueprint_variable<field_type> &x_6_2,
 const blueprint_variable<field_type> &x_6_3,
 const blueprint_variable<field_type> &x_6_4,
 const blueprint_variable<field_type> &x_6_5,
 const blueprint_variable<field_type> &x_6_6,
 const blueprint_variable<field_type> &x_6_7,
 const blueprint_variable<field_type> &x_6_8,
 const blueprint_variable<field_type> &x_7_0,
 const blueprint_variable<field_type> &x_7_1,
 const blueprint_variable<field_type> &x_7_2,
 const blueprint_variable<field_type> &x_7_3,
 const blueprint_variable<field_type> &x_7_4,
 const blueprint_variable<field_type> &x_7_5,
 const blueprint_variable<field_type> &x_7_6,
 const blueprint_variable<field_type> &x_7_7,
 const blueprint_variable<field_type> &x_7_8,
 const blueprint_variable<field_type> &x_8_0,
 const blueprint_variable<field_type> &x_8_1,
 const blueprint_variable<field_type> &x_8_2,
 const blueprint_variable<field_type> &x_8_3,
 const blueprint_variable<field_type> &x_8_4,
 const blueprint_variable<field_type> &x_8_5,
 const blueprint_variable<field_type> &x_8_6,
 const blueprint_variable<field_type> &x_8_7,
 const blueprint_variable<field_type> &x_8_8
                //const blueprint_variable<field_type> &out,
                //const blueprint_variable<field_type> &x
 ) :
      nil::crypto3::zk::components::component<field_type>(bp) ,free_x_0_0 (free_x_0_0),free_x_0_1 (free_x_0_1),free_x_0_2 (free_x_0_2),free_x_0_3 (free_x_0_3),free_x_0_4 (free_x_0_4),free_x_0_5 (free_x_0_5),free_x_0_6 (free_x_0_6),free_x_0_7 (free_x_0_7),free_x_0_8 (free_x_0_8),free_x_1_0 (free_x_1_0),free_x_1_1 (free_x_1_1),free_x_1_2 (free_x_1_2),free_x_1_3 (free_x_1_3),free_x_1_4 (free_x_1_4),free_x_1_5 (free_x_1_5),free_x_1_6 (free_x_1_6),free_x_1_7 (free_x_1_7),free_x_1_8 (free_x_1_8),free_x_2_0 (free_x_2_0),free_x_2_1 (free_x_2_1),free_x_2_2 (free_x_2_2),free_x_2_3 (free_x_2_3),free_x_2_4 (free_x_2_4),free_x_2_5 (free_x_2_5),free_x_2_6 (free_x_2_6),free_x_2_7 (free_x_2_7),free_x_2_8 (free_x_2_8),free_x_3_0 (free_x_3_0),free_x_3_1 (free_x_3_1),free_x_3_2 (free_x_3_2),free_x_3_3 (free_x_3_3),free_x_3_4 (free_x_3_4),free_x_3_5 (free_x_3_5),free_x_3_6 (free_x_3_6),free_x_3_7 (free_x_3_7),free_x_3_8 (free_x_3_8),free_x_4_0 (free_x_4_0),free_x_4_1 (free_x_4_1),free_x_4_2 (free_x_4_2),free_x_4_3 (free_x_4_3),free_x_4_4 (free_x_4_4),free_x_4_5 (free_x_4_5),free_x_4_6 (free_x_4_6),free_x_4_7 (free_x_4_7),free_x_4_8 (free_x_4_8),free_x_5_0 (free_x_5_0),free_x_5_1 (free_x_5_1),free_x_5_2 (free_x_5_2),free_x_5_3 (free_x_5_3),free_x_5_4 (free_x_5_4),free_x_5_5 (free_x_5_5),free_x_5_6 (free_x_5_6),free_x_5_7 (free_x_5_7),free_x_5_8 (free_x_5_8),free_x_6_0 (free_x_6_0),free_x_6_1 (free_x_6_1),free_x_6_2 (free_x_6_2),free_x_6_3 (free_x_6_3),free_x_6_4 (free_x_6_4),free_x_6_5 (free_x_6_5),free_x_6_6 (free_x_6_6),free_x_6_7 (free_x_6_7),free_x_6_8 (free_x_6_8),free_x_7_0 (free_x_7_0),free_x_7_1 (free_x_7_1),free_x_7_2 (free_x_7_2),free_x_7_3 (free_x_7_3),free_x_7_4 (free_x_7_4),free_x_7_5 (free_x_7_5),free_x_7_6 (free_x_7_6),free_x_7_7 (free_x_7_7),free_x_7_8 (free_x_7_8),free_x_8_0 (free_x_8_0),free_x_8_1 (free_x_8_1),free_x_8_2 (free_x_8_2),free_x_8_3 (free_x_8_3),free_x_8_4 (free_x_8_4),free_x_8_5 (free_x_8_5),free_x_8_6 (free_x_8_6),free_x_8_7 (free_x_8_7),free_x_8_8 (free_x_8_8),x_0_0 (x_0_0),x_0_1 (x_0_1),x_0_2 (x_0_2),x_0_3 (x_0_3),x_0_4 (x_0_4),x_0_5 (x_0_5),x_0_6 (x_0_6),x_0_7 (x_0_7),x_0_8 (x_0_8),x_1_0 (x_1_0),x_1_1 (x_1_1),x_1_2 (x_1_2),x_1_3 (x_1_3),x_1_4 (x_1_4),x_1_5 (x_1_5),x_1_6 (x_1_6),x_1_7 (x_1_7),x_1_8 (x_1_8),x_2_0 (x_2_0),x_2_1 (x_2_1),x_2_2 (x_2_2),x_2_3 (x_2_3),x_2_4 (x_2_4),x_2_5 (x_2_5),x_2_6 (x_2_6),x_2_7 (x_2_7),x_2_8 (x_2_8),x_3_0 (x_3_0),x_3_1 (x_3_1),x_3_2 (x_3_2),x_3_3 (x_3_3),x_3_4 (x_3_4),x_3_5 (x_3_5),x_3_6 (x_3_6),x_3_7 (x_3_7),x_3_8 (x_3_8),x_4_0 (x_4_0),x_4_1 (x_4_1),x_4_2 (x_4_2),x_4_3 (x_4_3),x_4_4 (x_4_4),x_4_5 (x_4_5),x_4_6 (x_4_6),x_4_7 (x_4_7),x_4_8 (x_4_8),x_5_0 (x_5_0),x_5_1 (x_5_1),x_5_2 (x_5_2),x_5_3 (x_5_3),x_5_4 (x_5_4),x_5_5 (x_5_5),x_5_6 (x_5_6),x_5_7 (x_5_7),x_5_8 (x_5_8),x_6_0 (x_6_0),x_6_1 (x_6_1),x_6_2 (x_6_2),x_6_3 (x_6_3),x_6_4 (x_6_4),x_6_5 (x_6_5),x_6_6 (x_6_6),x_6_7 (x_6_7),x_6_8 (x_6_8),x_7_0 (x_7_0),x_7_1 (x_7_1),x_7_2 (x_7_2),x_7_3 (x_7_3),x_7_4 (x_7_4),x_7_5 (x_7_5),x_7_6 (x_7_6),x_7_7 (x_7_7),x_7_8 (x_7_8),x_8_0 (x_8_0),x_8_1 (x_8_1),x_8_2 (x_8_2),x_8_3 (x_8_3),x_8_4 (x_8_4),x_8_5 (x_8_5),x_8_6 (x_8_6),x_8_7 (x_8_7),x_8_8 (x_8_8) {

      // Allocate variables to blueprint
      //allocate private variables to blueprint

      //sym_1.allocate(this->bp);
      //y.allocate(this->bp);
      //sym_2.allocate(this->bp);
    }

    void generate_r1cs_constraints() {

      // x*x = sym_1
      //this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(x, x, sym_1));

      // sym_1 * x = y
      //this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(sym_1, x, y));

      // y + x = sym_2
      //this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(y + x, 1, sym_2));

      // sym_2 + 5 = ~out
      //this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(sym_2 + 5, 1, out));
    }
};

#endif    // CRYPTO3_BLUEPRINT_SUDOKU_TEST_COMPONENT_HPP
