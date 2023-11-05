#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	//const int size = 3;
	TMatrix<int>* m;
	m = new TMatrix<int>(3);
	for (int i = 0; i < (*m).GetSize(); i++)
		for (int j = 0; j < (*m).GetSize(); j++)
			(*m)[i][j] = i;
	TMatrix<int> m1(*m);
	delete m;
	TMatrix<int> m2(3);
	for (int i = 0; i < m2.GetSize(); i++)
		for (int j = 0; j < (*m).GetSize(); j++)
			m2[i][j] = i;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int>* m;
	m = new TMatrix<int>(3);
	int s = (*m).GetSize();
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
		(*m)[i][j] = i;
	TMatrix<int> m1(*m);
	delete m;
	int s1 = m1.GetSize();
	EXPECT_EQ(s1, s);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[0][0] = 3;
	EXPECT_EQ(3, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);

	ASSERT_ANY_THROW(m[-1][-1] = 3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);

	ASSERT_ANY_THROW(m[5][5] = 3);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	const int size = 2;
	TMatrix<int> m(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i][j] = 1;
	m = m;
	EXPECT_EQ(1, m[0][0]);
	EXPECT_EQ(1, m[0][1]);
	EXPECT_EQ(1, m[1][0]);
	EXPECT_EQ(1, m[1][1]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 2;
	TMatrix<int> m(size),m1(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i][j] = 1;
	m1 = m;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int>* m;
	const int size = 7;
	m = new TMatrix<int>(size);
	EXPECT_EQ(7, (*m).GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int size = 2,size1=5;
	TMatrix<int> m(size), m1(size1);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i][j] = 1;
	m1 = m;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	const int size = 2;
	TMatrix<int> m(size), m1(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i][j] = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m1[i][j] = 1;
	ASSERT_TRUE(m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	const int size = 2;
	TMatrix<int> m(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i][j] = 1;
	ASSERT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int size = 2, size1 = 5;
	TMatrix<int> m(size), m1(size1);

	ASSERT_TRUE(m != m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int size = 2;
	TMatrix<int> m(size), m1(size), res;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i][j] = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m1[i][j] = 2;
	res = m + m1;
	EXPECT_EQ(3, res[0][0]);
	EXPECT_EQ(3, res[0][1]);
	EXPECT_EQ(3, res[1][0]);
	EXPECT_EQ(3, res[1][1]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	const int size = 2,size1=5;
	TMatrix<int> m(size), m1(size1), res;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i][j] = 1;
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size1; j++)
			m1[i][j] = 2;
	ASSERT_ANY_THROW(res = m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int size = 2;
	TMatrix<int> m(size), m1(size), res;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i] = 5;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m1[i] = 2;
	res = m - m1;
	EXPECT_EQ(3, res[0][0]);
	EXPECT_EQ(3, res[0][1]);
	EXPECT_EQ(3, res[1][0]);
	EXPECT_EQ(3, res[1][1]);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int size = 2, size1 = 5;
	TMatrix<int> m(size), m1(size1), res;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			m[i][j] = 1;
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size1; j++)
			m1[i][j] = 2;
	ASSERT_ANY_THROW(res = m - m1);
}

