//-------------------------------------------+
//8/30 改変by矢野
//-------------------------------------------+

#pragma once
#include"Dxlib.h"
#include"StaticObjectActor.h"
class Pool
{
public:
	/*Pool();
	~Pool();*/
//	void Delete() { MV1DeleteModel(mModelHandle); }													 //モデルデータの消去
//	void Draw() { MV1DrawModel(mModelHandle); }                                                      //描画処理
//	const VECTOR& mGetPoolPos()const { return mPos; }												 //位置を返す
//	void Load();
//	//回転値の単位はラジアンですので、度数単位の値を代入する場合は　度 * DX_PI_F / 180.0f　の計算をしてください
//	void Rotate(const VECTOR in_rotate) { MV1SetRotationXYZ(mModelHandle,in_rotate); }	             //回転　　
//	void ScaleControle(const VECTOR in_scale) { MV1SetScale(mModelHandle, in_scale); }	             //拡大縮小
//	void SetPos(const VECTOR in_pos) 																 //位置変更
//	{
//		MV1SetPosition(mModelHandle, in_pos); 
//		mPos = in_pos;
//	}						                                                                         
//
//private:
//	//VECTOR mPos;      //poolのほうにカメラを向くためのvector
//	int mModelHandle; //プールのモデル
};