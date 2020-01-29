#pragma once

struct Resolution {
	size_t width_;
	size_t height_;

	Resolution() }

	Resolution(size_t width, size_t height)
	{
		width_ = width;
		height_ = height;
	}
};