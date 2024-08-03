#include "RDCsvReader.h"
#include <iostream>

#include "Mesh.h"
#include "rapidcsv.h"
csv::RDCsvReader::RDCsvReader(std::string csv_file_name)
{
	rapidcsv::Document csv_file(csv_file_name,rapidcsv::LabelParams(),rapidcsv::SeparatorParams(',',true));

	_mesh = std::make_shared<mesh::Mesh>(csv_file.GetRowCount());
	_mesh->SetIndices(csv_file.GetColumn<int>("IDX"));
	// "VTX", "IDX", "POSITION.x", "POSITION.y", "POSITION.z", 
	// "NORMAL.x", "NORMAL.y", "NORMAL.z", "TANGENT.x", "TANGENT.y", "TANGENT.z", "TANGENT.w",
	// "COLOR.x", "COLOR.y", "COLOR.z", "COLOR.w", 
	// "TEXCOORD0.x", "TEXCOORD0.y", "TEXCOORD1.x", "TEXCOORD1.y", "TEXCOORD2.x", "TEXCOORD2.y", "TEXCOORD3.x", "TEXCOORD3.y");
	std::vector<float> tmp_x(_mesh->Size());
	std::vector<float> tmp_y(_mesh->Size());
	std::vector<float> tmp_z(_mesh->Size());
	std::vector<float> tmp_w(_mesh->Size());

	tmp_x = csv_file.GetColumn<float>("POSITION.x");
	tmp_y = csv_file.GetColumn<float>("POSITION.y");
	tmp_z = csv_file.GetColumn<float>("POSITION.z");
	_mesh->Set_Position(mesh::MakeArray3fVector(tmp_x, tmp_y, tmp_z));

	tmp_x = csv_file.GetColumn<float>("NORMAL.x");
	tmp_y = csv_file.GetColumn<float>("NORMAL.y");
	tmp_z = csv_file.GetColumn<float>("NORMAL.z");
	_mesh->Set_Normal(mesh::MakeArray3fVector(tmp_x, tmp_y, tmp_z));

	tmp_x = csv_file.GetColumn<float>("TANGENT.x");
	tmp_y = csv_file.GetColumn<float>("TANGENT.y");
	tmp_z = csv_file.GetColumn<float>("TANGENT.z");
	tmp_w = csv_file.GetColumn<float>("TANGENT.w");
	_mesh->Set_Tangent(mesh::MakeArray4fVector(tmp_x, tmp_y, tmp_z, tmp_w));

	tmp_x = csv_file.GetColumn<float>("COLOR.x");
	tmp_y = csv_file.GetColumn<float>("COLOR.y");
	tmp_z = csv_file.GetColumn<float>("COLOR.z");
	tmp_w = csv_file.GetColumn<float>("COLOR.w");
	_mesh->Set_Color(mesh::MakeArray4fVector(tmp_x, tmp_y, tmp_z, tmp_w));

	tmp_x = csv_file.GetColumn<float>("TEXCOORD0.x");
	tmp_y = csv_file.GetColumn<float>("TEXCOORD0.y");
	_mesh->Set_Texcoord0(mesh::MakeArray2fVector(tmp_x, tmp_y));
	tmp_x = csv_file.GetColumn<float>("TEXCOORD1.x");
	tmp_y = csv_file.GetColumn<float>("TEXCOORD1.y");
	_mesh->Set_Texcoord1(mesh::MakeArray2fVector(tmp_x, tmp_y));
	tmp_x = csv_file.GetColumn<float>("TEXCOORD2.x");
	tmp_y = csv_file.GetColumn<float>("TEXCOORD2.y");
	_mesh->Set_Texcoord2(mesh::MakeArray2fVector(tmp_x, tmp_y));
	tmp_x = csv_file.GetColumn<float>("TEXCOORD3.x");
	tmp_y = csv_file.GetColumn<float>("TEXCOORD3.y");
	_mesh->Set_Texcoord3(mesh::MakeArray2fVector(tmp_x, tmp_y));
}
