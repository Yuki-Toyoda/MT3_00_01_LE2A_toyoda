#include <Novice.h>
#include <Vector3.h>
#include <math.h>

const char kWindowTitle[] = "LE2A_11_トヨダユウキ";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

static const int kColumWidth = 60;

// 関数宣言
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%0.2f", vector.x); // x
	Novice::ScreenPrintf(x + kColumWidth, y, "%0.2f", vector.y); // y
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%0.2f", vector.z); // z
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%s", label);

}

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {

	// 結果格納用
	Vector3 result;

	// 計算処理
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;

}

// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {

	// 結果格納用
	Vector3 result;

	// 計算処理
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	return result;

}

// スカラー倍
Vector3 Multiply(float scalar, const Vector3& v) {

	// 結果格納用
	Vector3 result;

	// 計算処理
	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;

	return result;

}

// 内積
float Dot(const Vector3& v1, const Vector3& v2) {

	// 結果格納用
	float result;

	// 計算処理
	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	return result;

}

// 長さ
float Length(const Vector3& v) {
	
	// 計算処理
	return sqrtf(Dot(v, v));

}

// 正規化
Vector3 Normalize(const Vector3& v) {
	
	// 正規化するベクトルの長さを求める
	float length = Length(v);
	// 結果格納用
	Vector3 result;

	// 計算処理
	if (length != 0) {
		result.x = v.x / length;
		result.y = v.y / length;
		result.z = v.z / length;
	}

	return result;

}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// 変数宣言
	Vector3 v1 = { 1.0f, 3.0f, -5.0f };
	Vector3 v2 = { 4.0f, -1.0f, 2.0f };
	float k = { 4.0f };

	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubtract = Subtract(v1, v2);
	Vector3 resultMultiply = Multiply(k, v1);
	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v2);

	// 関数宣言

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, resultAdd, " : Add");
		VectorScreenPrintf(0, 20, resultSubtract, " : Subtract");
		VectorScreenPrintf(0, 40, resultMultiply, " : Multiply");
		Novice::ScreenPrintf(0, 60, "%.02f  : Dot", resultDot);
		Novice::ScreenPrintf(0, 80, "%.02f  : Length", resultLength);
		VectorScreenPrintf(0, 100, resultNormalize, " : Normalize");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
