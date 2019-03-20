#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <random>
#include "./Engine/System/D3D12System.h"
#include "./Engine/Input/GamePad.h"
#include "./Engine/GameConponent/Camera/Camera.h"
#include "./Engine/Input/InputManager.h"
#include "./Engine/GameConponent/Primitive/Cube.h"
#include "./Engine/Util/Math.h"
#include "./Engine/CommandContext/GraphicsCommandList.h"
#include "./Engine/Audio/Audio.h"
#include "./Engine/Audio/AudioManager.h"
#include "Engine/CommandContext/GraphicsContextLibrary.h"
#include "Engine/Timer/Timer.h"
#include "Engine/Particle/GPUParticle.h"

#define SPAWN_MAX 256 * 16
std::random_device randDev;
std::mt19937 dev(randDev());
std::uniform_real_distribution<float> rangex(-5.f, 5.f);
std::uniform_real_distribution<float> rangey(-5.f, 5.f);

int main() {
	Timer timer;

	K3D12::SetWindowSize(1280, 720);
	K3D12::SetWindowName(L"1601279_小林開人_D3D12");
	K3D12::Initialize();
	K3D12::D3D12System::InitializeCamera(K3D12::CameraMode::Perspective, 10.0f * Vector3::back, Vector3::zero, Vector3::up, 0.1f, 1000.0f);
	K3D12::AudioManager::InitializeXAudio2();
	//楽曲再生テスト
	//auto audio = K3D12::AudioManager::GetInstance().LoadAudio("./audio/An Ordeal From God.wav");
	//楽曲再生
	//audio->Play();

	K3D12::GPUParticle particle;
	timer.Start();
	timer.Tick();
	particle.Create(SPAWN_MAX, 16);
	float testTime = 0.0f;
	while (K3D12::MessageLoop() == 0 && !K3D12::Input().IsDown(K3D12::VIRTUAL_KEY_STATE::VKS_ESCAPE)) {
		timer.Tick();

		K3D12::Input().InputUpdate();
		K3D12::ClearScreen();
		float deltaTime = timer.DeltaTime();
		Vector3 pos;
		const float RAD = 2.0f;
		pos.x = rangex(dev) * RAD;
		pos.y = rangey(dev) * RAD;
		pos.x = rangex(dev) * RAD;
		pos.y = rangey(dev) * RAD;
		testTime += deltaTime;

		particle.Spawn(SPAWN_MAX, pos);		
		particle.Run(timer.DeltaTime());
		particle.Draw();


		K3D12::ScreenFlip();
	}
	//曲破棄
	//audio->Discard();
	timer.Stop();
	K3D12::Destroy();
	return 0;
};