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
	TMatrix<int> Mat1(5);
	Mat1[1][1] = 1;
	TMatrix<int> Mat2(Mat1);
	EXPECT_EQ(Mat2, Mat1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> Mat1(5);
	Mat1[1][1] = 1;
	TMatrix<int> Mat2(Mat1);
	Mat2[2][2] = 10;
	EXPECT_NE(Mat2[2][2], Mat1[1][1]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> Mat(5);
	EXPECT_EQ(5, Mat.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> Mat(5);
	Mat[2][2] = 3;
	EXPECT_EQ(3, Mat[2][2]);
	
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> Mat(5);
	ASSERT_ANY_THROW(Mat[1][-678] = 10);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> Mat(5);
	ASSERT_ANY_THROW(Mat[1][678] = 10);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> Mat(5);
	Mat[2][2] = 4;
	ASSERT_NO_THROW(Mat = Mat);
  
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> Mat(5), Mat1(5);
	Mat[2][2] = 4;
	ASSERT_NO_THROW(Mat = Mat1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> Mat(5), Mat1(7);
	Mat[2][2] = 4;
	Mat1 = Mat;
	EXPECT_EQ(5, Mat1.GetSize());
}
TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> Mat(5), Mat1(6);
	Mat[2][2] = 4;
	Mat1 = Mat;
	EXPECT_EQ(Mat, Mat1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> Mat(5), Mat1(5);
	Mat[2][2] = 4;
	Mat1[2][2] = 4; 
	ASSERT_TRUE(Mat == Mat1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> Mat(5);
	Mat[2][2] = 4;
	ASSERT_TRUE(Mat == Mat);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> Mat(5), Mat1(7);
	Mat[2][2] = 4;
	Mat1[2][2] = 4;
	ASSERT_FALSE(Mat == Mat1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> Mat(5), Mat1(5);
	Mat[2][2] = 4;
	Mat1[2][2] = 5;
	ASSERT_NO_THROW(Mat + Mat1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> Mat(5), Mat1(6);
	Mat[2][2] = 4;
	Mat1[2][2] = 5;
	ASSERT_ANY_THROW(Mat + Mat1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> Mat(5), Mat1(5);
	Mat[2][2] = 4;
	Mat1[2][2] = 5;
	ASSERT_NO_THROW(Mat - Mat1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> Mat(5), Mat1(6);
	Mat[2][2] = 4;
	Mat1[2][2] = 5;
	ASSERT_ANY_THROW(Mat - Mat1);
}

