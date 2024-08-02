#pragma once
#include <array>
#include <vector>

namespace mesh {
	typedef std::array<float, 3>  Position;
	typedef std::array<float, 3>  Normal;
	typedef std::array<float, 4>  Tangent;
	typedef std::array<float, 4>  Color;
	typedef std::array<float, 2>  Texcoord0;
	typedef std::array<float, 2>  Texcoord1;
	typedef std::array<float, 2>  Texcoord2;
	typedef std::array<float, 2>  Texcoord3;

#define DefineFunc_Mesh_Has_Member(Type) \
inline bool Has_##Type()\
{\
	return m_##Type.size()>0;\
}

	class Mesh {
	public:
		Mesh();
		Mesh(unsigned int size);
		DefineFunc_Mesh_Has_Member(Position)
		DefineFunc_Mesh_Has_Member(Normal)
		DefineFunc_Mesh_Has_Member(Tangent)
		DefineFunc_Mesh_Has_Member(Color)
		DefineFunc_Mesh_Has_Member(Texcoord0)
		DefineFunc_Mesh_Has_Member(Texcoord1)
		DefineFunc_Mesh_Has_Member(Texcoord2)
		DefineFunc_Mesh_Has_Member(Texcoord3)
	public:
		std::vector<Position> m_Position;
		std::vector<Normal> m_Normal;
		std::vector<Tangent> m_Tangent;
		std::vector<Color> m_Color;
		std::vector<Texcoord0> m_Texcoord0;
		std::vector<Texcoord1> m_Texcoord1;
		std::vector<Texcoord2> m_Texcoord2;
		std::vector<Texcoord3> m_Texcoord3;
	private:
		unsigned int size;
	};
}