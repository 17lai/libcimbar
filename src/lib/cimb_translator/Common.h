#pragma once

#include <opencv2/opencv.hpp>
#include <string>

namespace cimbar
{
	using RGB = std::tuple<uchar,uchar,uchar>;

	cv::Mat load_img(std::string path, const std::string& image_dir="");

	std::tuple<uchar,uchar,uchar> getColor(unsigned index, unsigned num_colors);
	cv::Mat getTile(unsigned symbol_bits, unsigned symbol, bool dark=true, unsigned num_colors=4, unsigned color=0, const std::string& image_dir="");
	cv::Mat getTile(unsigned symbol_bits, unsigned symbol, bool dark, const std::string& image_dir, unsigned num_colors=4, unsigned color=0);
}
