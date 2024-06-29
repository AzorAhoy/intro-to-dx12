#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;
// Overload the "<<" operators so that we can use cout to
// output XMVECTOR objects.
//ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR
//	v)
//{
//	XMFLOAT3 dest;
//	XMStoreFloat3(&dest, v);
//	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
//	return os;
//}

//int main()
//{
//	cout.setf(ios_base::boolalpha);
//	// check support for sse2 (pentium4, amd k8, and above).
//	if (!xmverifycpusupport())
//	{
//		cout << "directx math not supported" << endl;
//		return 0;
//	}
//	xmvector n = xmvectorset(1.0f, 0.0f, 0.0f, 0.0f);
//	xmvector u = xmvectorset(1.0f, 2.0f, 3.0f, 0.0f);
//	xmvector v = xmvectorset(-2.0f, 1.0f, -3.0f, 0.0f);
//	xmvector w = xmvectorset(0.707f, 0.707f, 0.0f,
//		0.0f);
//	// vector addition: xmvector operator +
//	xmvector a = u + v;
//	// vector subtraction: xmvector operator -
//	xmvector b = u - v;
//	// scalar multiplication: xmvector operator *
//	xmvector c = 10.0f * u;
//	// ||u||
//	xmvector l = xmvector3length(u);
//	// d = u / ||u||
//	xmvector d = xmvector3normalize(u);
//	// s = u dot v
//	xmvector s = xmvector3dot(u, v);
//	// e = u x v
//	xmvector e = xmvector3cross(u, v);
//	// find proj_n(w) and perp_n(w)
//	xmvector projw;
//	xmvector perpw;
//	xmvector3componentsfromnormal(&projw, &perpw, w, n);
//	// does projw + perpw == w?
//	bool equal = xmvector3equal(projw + perpw, w) != 0;
//	bool notequal = xmvector3notequal(projw + perpw, w)
//		!= 0;
//	// the angle between projw and perpw should be 90 degrees.
//	xmvector anglevec = xmvector3anglebetweenvectors(projw, perpw);
//	float angleradians = xmvectorgetx(anglevec);
//	float angledegrees = xmconverttodegrees(angleradians);
//	cout << "u = " << u << endl;
//	cout << "v = " << v << endl;
//	cout << "w = " << w << endl;
//	cout << "n = " << n << endl;
//	cout << "a = u + v = " << a << endl;
//	cout << "b = u - v = " << b << endl;
//	cout << "c = 10 * u = " << c << endl;
//	cout << "d = u / ||u || = " << d << endl;
//	cout << "e = u x v = " << e << endl;
//	cout << "l = || u || = " << l << endl;
//	cout << "s = u.v = " << s << endl;
//	cout << "projw = " << projw << endl;
//	cout << "perpw = " << perpw << endl;
//	cout << "projw + perpw == w = " << equal << endl;
//	cout << "projw + perpw != w = " << notequal << endl;
//	cout << "angle = " << angledegrees << endl;
//
//	return 0;
//}

//int main()
//{
//	cout.precision(8);
//	// Check support for SSE2 (Pentium4, AMD K8, and above).
//	if (!XMVerifyCPUSupport())
//	{
//		cout << "directx math not supported" << endl;
//		return 0;
//	}
//	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
//	XMVECTOR n = XMVector3Normalize(u);
//	float LU = XMVectorGetX(XMVector3Length(n));
//	// Mathematically, the length should be 1. Is it numerically ?
//		cout << LU << endl;
//	if (LU == 1.0f)
//		cout << "Length 1" << endl;
//	else
//		cout << "Length not 1" << endl;
//	// Raising 1 to any power should still be 1. Is it?
//	float powLU = powf(LU, 1.0e6f);
//	cout << "LU ^ (10 ^ 6) = " << powLU << endl;
//
//	return 0;
//}

// Overload the "<<" operators so that we can use cout to
// output XMVECTOR objects.
ostream& XM_CALLCONV operator<<(ostream& os,
	FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);
	os << "(" << dest.x << ", " << dest.y << ", "
		<< dest.z << ", " << dest.w << ")";
	return os;
}

int main()
{
	cout.setf(ios_base::boolalpha);
	// Check support for SSE2 (Pentium4, AMD K8, and above).
	if (!XMVerifyCPUSupport())
	{
		cout << "directx math not supported" << endl;
		return 0;
	}
	XMVECTOR p = XMVectorSet(2.0f, 2.0f, 1.0f, 0.0f);
	XMVECTOR q = XMVectorSet(2.0f, -0.5f, 0.5f,
		0.1f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 4.0f, 8.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f,
		2.5f);
	XMVECTOR w = XMVectorSet(0.0f, XM_PIDIV4,
		XM_PIDIV2, XM_PI);
	cout << "XMVectorAbs(v) = " <<
		XMVectorAbs(v) << endl;
	cout << "XMVectorCos(w) = " <<
		XMVectorCos(w) << endl;
	cout << "XMVectorLog(u) = " <<
		XMVectorLog(u) << endl;
	cout << "XMVectorExp(p) = " <<
		XMVectorExp(p) << endl;
	cout << "XMVectorPow(u, p) = " <<
		XMVectorPow(u, p) << endl;
	cout << "XMVectorSqrt(u) = " <<
		XMVectorSqrt(u) << endl;
	cout << "XMVectorSwizzle(u, 2, 2, 1, 3) = "
		<< XMVectorSwizzle(u, 2, 2, 1, 3) << endl;
	cout << "XMVectorSwizzle(u, 2, 1, 0, 3) = "
		<< XMVectorSwizzle(u, 2, 1, 0, 3) << endl;
	cout << "XMVectorMultiply(u, v) = " <<
		XMVectorMultiply(u, v) << endl;
	cout << "XMVectorSaturate(q) = " <<
		XMVectorSaturate(q) << endl;
	cout << "XMVectorMin(p, v = " <<
		XMVectorMin(p, v) << endl;
	cout << "XMVectorMax(p, v) = " <<
		XMVectorMax(p, v) << endl;
	return 0;
}