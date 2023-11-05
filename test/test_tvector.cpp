#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> *v;
	v = new TVector<int>(3);
	for (int i = 0; i < (*v).GetSize(); i++)
		(*v)[i] = i;
	TVector<int> v1(*v);
	delete v;
	TVector<int> v2(3);
	for (int i = 0; i < v2.GetSize(); i++)
		v2[i] = i;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int>* v;
	v = new TVector<int>(3);
	int s = (*v).GetSize();
	for (int i = 0; i < s; i++)
		(*v)[i] = i;
	TVector<int> v1(*v);
	delete v;
	int s1 = v1.GetSize();
	EXPECT_EQ(s1, s);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[-1]=3);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[5] = 3);
}

TEST(TVector, can_assign_vector_to_itself)
{
	const int size = 2;
	TVector<int> v(size);
	for (int i = 0; i < size; i++)
		v[i] = 1;
	v = v;
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(1, v[1]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int size = 5;
	TVector<int> v(size), v1(size);
	for (int i = 0; i < size; i++)
		v[i] = 1;
	v1 = v;
	EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> *v;
	const int size = 7;
	v = new TVector<int>(size);
	EXPECT_EQ(7,(*v).GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	const int size = 2, size1=5;
	TVector<int> v(size), v1(size1);
	for (int i = 0; i < size; i++)
		v[i] = 1;
	v1 = v;
	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	const int size = 5;
	TVector<int> v(size), v1(size);
	for (int i = 0; i < size; i++)
		v[i] = 1;
	for (int i = 0; i < size; i++)
		v1[i] = 1;
	ASSERT_TRUE(v==v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	const int size = 5;
	TVector<int> v(size);
	for (int i = 0; i < size; i++)
		v[i] = 1;
	ASSERT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	const int size = 2, size1 = 5;
	TVector<int> v(size), v1(size1);

	ASSERT_TRUE(v!=v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	const int size = 2;
	TVector<int> v(size);
	for (int i = 0; i < size; i++)
		v[i] = 0;
	const int val = 3;
	v = v + val;
	EXPECT_EQ(3, v[0]);
	EXPECT_EQ(3, v[1]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	const int size = 2;
	TVector<int> v(size);
	for (int i = 0; i < size; i++)
		v[i] = 1;
	const int val = 1;
	v = v - val;
	EXPECT_EQ(0, v[0]);
	EXPECT_EQ(0, v[1]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	const int size = 2;
	TVector<int> v(size);
	for (int i = 0; i < size; i++)
		v[i] = 2;
	const int val = 3;
	v = v * val;
	EXPECT_EQ(6, v[0]);
	EXPECT_EQ(6, v[1]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	const int size = 2;
	TVector<int> v(size), v1(size),res;
	for (int i = 0; i < size; i++)
		v[i] = 1;
	for (int i = 0; i < size; i++)
		v1[i] = 2;
	res = v + v1;
	EXPECT_EQ(3, res[0]);
	EXPECT_EQ(3, res[1]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	const int size = 2, size1 = 5;
	TVector<int> v(size), v1(size1),res;
	for (int i = 0; i < size; i++)
		v[i] = 1;
	for (int i = 0; i < size1; i++)
		v1[i] = 1;
	ASSERT_ANY_THROW(res=v+v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	const int size = 2;
	TVector<int> v(size), v1(size), res;
	for (int i = 0; i < size; i++)
		v[i] = 5;
	for (int i = 0; i < size; i++)
		v1[i] = 2;
	res = v - v1;
	EXPECT_EQ(3, res[0]);
	EXPECT_EQ(3, res[1]);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	const int size = 2, size1 = 5;
	TVector<int> v(size), v1(size1), res;
	for (int i = 0; i < size; i++)
		v[i] = 1;
	for (int i = 0; i < size1; i++)
		v1[i] = 1;
	ASSERT_ANY_THROW(res = v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	const int size = 2;
	TVector<int> v(size), v1(size); int res;
	for (int i = 0; i < size; i++)
		v[i] = 5;
	for (int i = 0; i < size; i++)
		v1[i] = 2;
	res = v * v1;
	EXPECT_EQ(20, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	const int size = 2, size1 = 5;
	TVector<int> v(size), v1(size1);int res;
	for (int i = 0; i < size; i++)
		v[i] = 1;
	for (int i = 0; i < size1; i++)
		v1[i] = 1;
	ASSERT_ANY_THROW(res = v * v1);
}

