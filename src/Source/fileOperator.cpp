#include "fileOperator.h"

#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<fstream>
#include<sstream>
#include<vector>
#include<Eigen/Dense>
using namespace std;


// float3::float3() { x=0;y=0;z=0; }
// float3::float3(float mx, float my, float mz):x(mx),y(my),z(mz) {}
// float3::~float3() {}
// float3 float3::operator + (float3 m)
// {
// 	float3 temp;
// 	temp.x = x + m.x;
// 	temp.y = y + m.y;
// 	temp.z = z + m.z;
// 	return temp;
// }

// float3 float3::operator - (float3 m)
// {
// 	float3 temp;
// 	temp.x = x - m.x;
// 	temp.y = y - m.y;
// 	temp.z = z - m.z;
// 	return temp;
// }
// float3 float3::operator / (float m)
// {
// 	if(m == 0)
// 	{
// 		printf("error :");
// 		return float3(x,y,z);
// 	}
// 	else
// 	{
// 		return float3(x/m,y/m,z/m);
// 	}
// }

// float3 operator * (float m, float3 f3) {
// 	return float3(f3.x*m, f3.y*m, f3.z*m);

// } 
// float3 operator * (float3 f3, float m) {
// 	return float3(f3.x*m, f3.y*m, f3.z*m);
// }
// float3 float3::operator = (float3 m)
// {
// 	x = m.x;
// 	y = m.y;
// 	z = m.z;
// }

void readFileBase::loadObjBase(const std::string filename, TriangleMesh &mesh)
{
	std::ifstream in(filename.c_str());
	if(!in.good())
	{
		std::cout << "ERROR: loading obj:(" << filename << ") file is not good" << "\n";
		exit(0);
	}
	std::string line;

	while(!in.eof())
	{
		std::getline(in,line);
		std::istringstream iss(line.c_str());
		char trash;
		if(!line.compare(0, 2, "v "))
		{
			iss >> trash;
			float x,y,z;
			iss >> x >> y >> z;
			mesh.verts.push_back(Eigen::Vector3f(x, y, z));
		}
		else if(!line.compare(0, 3, "vn "))
		{
			iss >> trash >> trash;
			float x, y, z;
			iss >> x >> y >> z;
			mesh.norms.push_back(Eigen::Vector3f(x, y, z));
		}
		else if(!line.compare(0, 3, "vt "))
		{
			iss >> trash >> trash;
			float x, y;
			iss >> x >> y;
			mesh.uv.push_back(Eigen::Vector2f(x, y));
		}
		else if(!line.compare(0, 2, "f "))
		{
			iss >> trash;
			int vIndex, uvIndex, nIndex;
			std::vector<Eigen::Vector3i> f;
			while (iss >> vIndex >> trash >> uvIndex >> trash >> nIndex)
			{
				vIndex --; uvIndex --; nIndex --;
				f.push_back(Eigen::Vector3i(vIndex, uvIndex, nIndex));
			}
			mesh.faces.push_back(f);
		}
	}
}

void readFileBase::calculateAABB()
{
	mesh.bounding_box[0] = mesh.verts[0];
	mesh.bounding_box[1] = mesh.verts[1];

	for (size_t i = 1; i < mesh.verts.size(); i++)
	{
		mesh.bounding_box[0](0) = std::min(mesh.verts[i](0), mesh.bounding_box[0](0));
		mesh.bounding_box[0](1) = std::min(mesh.verts[i](1), mesh.bounding_box[0](1));
		mesh.bounding_box[0](2) = std::min(mesh.verts[i](2), mesh.bounding_box[0](2));

		mesh.bounding_box[1](0) = std::max(mesh.verts[i](0), mesh.bounding_box[1](0));
		mesh.bounding_box[1](1) = std::max(mesh.verts[i](0), mesh.bounding_box[1](1));
		mesh.bounding_box[1](2) = std::max(mesh.verts[i](0), mesh.bounding_box[1](2));
	}
	
}