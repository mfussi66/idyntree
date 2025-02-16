// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <iDynTree/Core/VectorDynSize.h>
#include <iDynTree/Core/VectorFixSize.h>
#include <iDynTree/Core/TestUtils.h>


using namespace iDynTree;

int main()
{
    VectorDynSize vec;

    ASSERT_EQUAL_DOUBLE(vec.size(),0);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),0);

    vec.resize(10);

    ASSERT_EQUAL_DOUBLE(vec.size(),10);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),10);

    vec.reserve(20);

    ASSERT_EQUAL_DOUBLE(vec.size(),10);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),20);

    vec.reserve(30);

    ASSERT_EQUAL_DOUBLE(vec.size(),10);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),30);

    vec.resize(15);

    ASSERT_EQUAL_DOUBLE(vec.size(),15);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),30);

    vec.shrink_to_fit();

    ASSERT_EQUAL_DOUBLE(vec.size(),15);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),15);


    VectorDynSize test1, testToSpan;
    testToSpan.resize(15);
    iDynTree::getRandomVector(testToSpan);

    test1 = iDynTree::make_span(testToSpan);
    ASSERT_EQUAL_VECTOR(test1, testToSpan);

    iDynTree::Vector16 test2, check;
    iDynTree::getRandomVector(test2);
    check = iDynTree::make_span(test2);
    ASSERT_EQUAL_VECTOR(test2, check);

    return EXIT_SUCCESS;
}
