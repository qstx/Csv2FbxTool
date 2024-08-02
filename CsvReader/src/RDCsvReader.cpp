#include "RDCsvReader.h"
#include <iostream>
csv::RDCsvReader::RDCsvReader(std::string csv_file)
{
	io::CSVReader<24> in(csv_file);
	in.read_header(io::ignore_missing_column, "VTX", "IDX", "POSITION.x", "POSITION.y", "POSITION.z", "NORMAL.x", "NORMAL.y", "NORMAL.z", "TANGENT.x", "TANGENT.y", "TANGENT.z", "TANGENT.w", "COLOR.x", "COLOR.y", "COLOR.z", "COLOR.w", "TEXCOORD0.x", "TEXCOORD0.y", "TEXCOORD1.x", "TEXCOORD1.y", "TEXCOORD2.x", "TEXCOORD2.y", "TEXCOORD3.x", "TEXCOORD3.y");
	std::cout << in.get_file_line() << std::endl;
	int vtx, idx;
	float position_x, position_y, position_z;
	float normal_x, normal_y, normal_z;
	float tangent_x, tangent_y, tangent_z, tangent_w;
	float color_x, color_y, color_z, color_w;
	float texcoord0_x, texcoord0_y;
	float texcoord1_x, texcoord1_y;
	float texcoord2_x, texcoord2_y;
	float texcoord3_x, texcoord3_y;
	while (in.read_row(
		vtx,idx,
		position_x,position_y,position_z,
		normal_x, normal_y, normal_z,
		tangent_x, tangent_y, tangent_z, tangent_w,
		color_x, color_y, color_z, color_w,
		texcoord0_x, texcoord0_y,
		texcoord1_x, texcoord1_y,
		texcoord2_x, texcoord2_y,
		texcoord3_x, texcoord3_y
	)) {
		break;
	}
}
