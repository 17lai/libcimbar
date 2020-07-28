#include "unittest.h"

#include "CimbEncoder.h"

#include "cimb_translator/Common.h"
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>
#include <vector>
using std::string;

TEST_CASE( "CimbEncoderTest/testSimple", "[unit]" )
{
	CimbEncoder cw(4, 0);
	cv::Mat res = cw.encode(14);

	string root = TestCimbar::getProjectDir();
	cv::Mat expected = cimbar::getTile(4, 14, true, root);

	REQUIRE(cv::sum(expected != res) == cv::Scalar(0,0,0,0));
}

TEST_CASE( "CimbEncoderTest/testColor", "[unit]" )
{
	CimbEncoder cw(4, 3);
	cv::Mat res = cw.encode(55);

	string root = TestCimbar::getProjectDir();
	cv::Mat expected = cimbar::getTile(4, 7, true, root, 8, 3); // 3*16 + 7 == 55

	REQUIRE(cv::sum(expected != res) == cv::Scalar(0,0,0,0));
}

