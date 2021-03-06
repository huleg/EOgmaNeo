// ----------------------------------------------------------------------------
//  EOgmaNeo
//  Copyright(c) 2017 Ogma Intelligent Systems Corp. All rights reserved.
//
//  This copy of EOgmaNeo is licensed to you under the terms described
//  in the EOGMANEO_LICENSE.md file included in this distribution.
// ----------------------------------------------------------------------------

#pragma once

#include "ThreadPool.h"

#include <random>

namespace eogmaneo {
    class ThreadPool;

	/*!
	\brief Compute system. Mainly passed to other functions. Contains thread pooling and random number generator information.
	*/
    class ComputeSystem {
	private:
		ThreadPool _pool;
		std::mt19937 _rng;

	public:
		/*!
		\brief Initialize the system.
		\param numWorkers number of thread pool worker threads.
		\param seed global random number generator seed. Defaults to 1234.
		*/
        ComputeSystem(size_t numWorkers, unsigned long seed = 1234) {
			_pool.create(numWorkers);
			_rng.seed(seed);
		}
		
		friend class Layer;
		friend class Hierarchy;
        friend class ImageEncoder;
		friend class RandomEncoder;
        friend class GaborEncoder;
		friend class CornerEncoder;
		friend class LocalRegressor;
		
		friend std::vector<float> whiten(const std::vector<float> &src, int width, int radius, float strength, ComputeSystem &cs, int chunkSize);
        friend std::vector<float> sobel(const std::vector<float> &src, int width, float clip, ComputeSystem &cs, int chunkSize);
    };
}