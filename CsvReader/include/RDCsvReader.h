#pragma once
#include <vector>
#include <memory>
#include <iostream>

namespace mesh {
	class Mesh;
}

namespace csv {
	class RDCsvReader {
	public:
		RDCsvReader(std::string csv_file_name);
		inline std::shared_ptr<mesh::Mesh> GetMesh() {
			return _mesh;
		}
	private:
		std::shared_ptr<mesh::Mesh> _mesh;
	};
}