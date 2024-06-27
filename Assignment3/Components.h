#pragma once
#include "Animation.h"
#include "Assets.h"

class Component
{
public:
	bool has = false;
};

class CTransform : public Component
{
public:
	Vec2 pos = { 0.0, 0.0 };
	Vec2 prevPos = { 0.0, 0.0 };
	Vec2 scale = { 1.0, 1.0 };
	Vec2 velocity = { 0.0, 0.0 };
	float angle = 0;

	CTransform() {}
	CTransform(const Vec2& p) :pos(p) {}
	~CTransform() {}

};

class CLifeSpan
{

};

class CBoundingBox
{

};

class CAnimation
{

};

class CGravity
{

};

class CState
{

};
class CInput
{
public:
	bool left = false;
	bool right = false;
	bool jump = false;
	bool shoot = false;
	CInput(){}
};