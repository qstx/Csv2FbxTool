#pragma once
#include <vector>

#include "csv.h"
#include "Mesh.h"

namespace csv {
	class RDCsvReader {
	public:
		RDCsvReader(std::string csv_file);
	private:
		mesh::Mesh _mesh;
	};
}