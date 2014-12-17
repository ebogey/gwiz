#include "gtest/gtest.h"

#include "graph/IGraph.h"
#include "core/IVariant.h"
#include "core/IReference.h"

namespace
{

// The fixture for testing class Foo.
	class VariantsTest : public ::testing::Test
	{
	protected:
		// You can remove any or all of the following functions if its body
		// is empty.

		VariantsTest()
		{
				// You can do set-up work for each test here.
		}

		virtual ~VariantsTest()
		{
			// You can do clean-up work that doesn't throw exceptions here.
	    }

		// If the constructor and destructor are not enough for setting up
		// and cleaning up each test, you can define the following methods:

		virtual void SetUp()
		{
			// Code here will be called immediately after the constructor (right
			// before each test).
		}

		virtual void TearDown()
		{
			// Code here will be called immediately after each test (right
			// before the destructor).
		}

		// Objects declared here can be used by all tests in the test case for Foo.
	};

	// Tests that the Foo::Bar() method does Abc.
	TEST_F(VariantsTest, OpenVariantFile)
	{

		/*
		const string input_filepath = "this/package/testdata/myinputfile.dat";
		const string output_filepath = "this/package/testdata/myoutputfile.dat";
		Foo f;
		EXPECT_EQ(0, f.Bar(input_filepath, output_filepath));
		*/
		EXPECT_EQ(0, 0);
	}
}