#pragma once
#include <array>
#include <vector>
#include <assert.h>

namespace mesh {
	typedef std::array<int, 3>  Face;
	typedef std::array<float, 3>  Position;
	typedef std::array<float, 3>  Normal;
	typedef std::array<float, 4>  Tangent;
	typedef std::array<float, 4>  Color;
	typedef std::array<float, 2>  Texcoord0;
	typedef std::array<float, 2>  Texcoord1;
	typedef std::array<float, 2>  Texcoord2;
	typedef std::array<float, 2>  Texcoord3;
	std::vector<std::array<int, 3>> MakeArray3iVector(std::vector<int> x, std::vector<int> y, std::vector<int> z);
	std::vector<std::array<float, 2>> MakeArray2fVector(std::vector<float> x, std::vector<float> y);
	std::vector<std::array<float, 3>> MakeArray3fVector(std::vector<float> x, std::vector<float> y, std::vector<float> z);
	std::vector<std::array<float, 4>> MakeArray4fVector(std::vector<float> x, std::vector<float> y, std::vector<float> z, std::vector<float> w);

#define DefineFunc_Mesh_Has_Member(Type) \
inline bool Has_##Type()\
{\
	return m_##Type.size()>0;\
}

#define DefineFunc_Mesh_Set_Member(Type) \
bool Set_##Type(std::vector<Type> m)\
{\
	m_##Type.resize(this->size);\
	for(int i=0;i<m.size();++i){\
		unsigned int idx =indices[i];\
		m_##Type[idx] = m[i];\
	}\
	return true;\
}
#define DefineFunc_Mesh_Get_Member(Type) \
Type Get_##Type(int idx)\
{\
	assert(idx<this->size);\
	return m_##Type[idx];\
}

#define Define_Mesh_Member(Type) \
std::vector<Type> m_##Type;\
DefineFunc_Mesh_Has_Member(Type)\
DefineFunc_Mesh_Set_Member(Type)\
DefineFunc_Mesh_Get_Member(Type)

	class Mesh {
	public:
		Mesh();
		Mesh(unsigned int size);
		Define_Mesh_Member(Position)
		Define_Mesh_Member(Normal)
		Define_Mesh_Member(Tangent)
		Define_Mesh_Member(Color)
		Define_Mesh_Member(Texcoord0)
		Define_Mesh_Member(Texcoord1)
		Define_Mesh_Member(Texcoord2)
		Define_Mesh_Member(Texcoord3)
		void SetIndices(std::vector<int>&& indices);
		inline unsigned int Size() { return this->size; }
	public:
		std::vector<int> indices;
		std::vector<Face> faces;
	private:
		unsigned int size;
	};
}