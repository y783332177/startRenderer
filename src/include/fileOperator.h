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

// class float3
// {
// public:
// 	float x;
// 	float y;
// 	float z;
// public:
// 	float3();
// 	float3(float mx, float my, float mz);
// 	~float3();
// 	float3 operator+(float3);
// 	float3 operator-(float3);
// 	float3 operator/(float);
// 	friend float3 operator*(float m, float3 f3);
// 	friend float3 operator*(float3 f3, float m);
// 	float3 operator=(float3);
// 	float3& operator += (float3);
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

class readFileBase
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

class writeFileBase
{

};

#endif
