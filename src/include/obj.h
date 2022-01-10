#include "fileOperator.h"

class ObjReader : public ReadFileBase
{
public:
	TriangleMesh mesh;
	int total_number_of_triangles = 0;
	// Scene bounding box;
	Eigen::Vector3f scene_aabbox_min;
	Eigen::Vector3f scene_aabbox_max;
	void loadObjBase(const std::string filename, TriangleMesh &mesh);
	void calculateAABB();
};