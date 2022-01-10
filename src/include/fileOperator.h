#ifndef _LOADOBJ_H
#define _LOADOBJ_H

#include<vector>
#include<queue>
#include<iostream>
#include<string>
#include<math.h>
#include<fstream>
#include<Eigen/Dense>

// struct TriangleFace
// {
// 	int v[3];
// };

struct TriangleMesh
{
	std::vector<Eigen::Vector3f> verts;
	std::vector<Eigen::Vector3f> norms;
	std::vector<Eigen::Vector2f> uv;
	std::vector<std::vector<Eigen::Vector3i>> faces;
	Eigen::Vector3f bounding_box[2];
	Eigen::Vector3f bounding_sphere_c;
	float bouding_sphere_r;
};


class ReadFileBase
{
    
};

class WriteFileBase
{

};

#endif
