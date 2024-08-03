#include "Mesh.h"
#include <algorithm>
#include <assert.h>

namespace mesh {
	std::vector<std::array<int, 3>> MakeArray3iVector(std::vector<int> x, std::vector<int> y, std::vector<int> z)
	{
		assert(x.size() == y.size() && y.size() == z.size());
		std::vector<std::array<int, 3>> ret(x.size());
		for (int i = 0; i < x.size(); ++i) {
			ret[i] = { x[i],y[i],z[i] };
		}
		return ret;
	}
	std::vector<std::array<float, 2>> MakeArray2fVector(std::vector<float> x, std::vector<float> y)
	{
		assert(x.size() == y.size());
		std::vector<std::array<float, 2>> ret(x.size());
		for (int i = 0; i < x.size(); ++i) {
			ret[i] = { x[i],y[i]};
		}
		return ret;
	}
	std::vector<std::array<float, 3>> MakeArray3fVector(std::vector<float> x, std::vector<float> y, std::vector<float> z) {
		assert(x.size() == y.size() && y.size() == z.size());
		std::vector<std::array<float, 3>> ret(x.size());
		for (int i = 0; i < x.size(); ++i) {
			ret[i] = { x[i],y[i],z[i] };
		}
		return ret;
	}
	std::vector<std::array<float, 4>> MakeArray4fVector(std::vector<float> x, std::vector<float> y, std::vector<float> z, std::vector<float> w) {
		assert(x.size() == y.size() && y.size() == z.size() && z.size() == w.size());
		std::vector<std::array<float, 4>> ret(x.size());
		for (int i = 0; i < x.size(); ++i) {
			ret[i] = { x[i],y[i],z[i],w[i] };
		}
		return ret;
	}
	Mesh::Mesh() :size(0)
	{
	}

	Mesh::Mesh(unsigned int size) :
		size(size)/*,
		m_Position(size),m_Normal(size),m_Tangent(size),m_Color(size),
		m_Texcoord0(size), m_Texcoord1(size), m_Texcoord2(size), m_Texcoord3(size)*/
	{
	}
	void Mesh::SetIndices(std::vector<int>&& indices) {
		assert(indices.size() > 0);
		this->indices = indices;
		size = *std::max_element(this->indices.begin(), this->indices.end())+1;

		faces.reserve(size / 3);
		for (int i = 0; i < this->indices.size(); i += 3) {
			faces.push_back({ indices[i], indices[i + 1], indices[i + 2] });
		}
	}
}
