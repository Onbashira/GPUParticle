#pragma once
#include "../Util/D3D12Common.h"
#include "../DescriptorHeap/DescriptorHeap.h"
#include "Resource.h"
#include "ByteAddressBuffer.h"

namespace K3D12 {

	class GraphicsCommandList;
	class CommandQueue;

	//UAV��DXGI_FORMAT��UNKNWON�Œ�
	class UnorderedAccessValue : public K3D12::Resource
	{
	public:
		enum BUFFER_MODE {
			UAV_BUFFER_MODE_APPEND,
			UAV_BUFFER_MODE_CONSUME

		};

	private:
		//Heap�̃I�t�Z�b�g�l
		enum HEAP_OFFSET
		{
			UAV_DESCRIPTOR_OFFSET = 0,
			SRV_DESCRIPTOR_OFFSET = 1,
			HEAP_OFFSET_MAX,
		};
		//CounterReosurce
		ByteAddressBuffer						_counterResource;
		//�X�e�[�W���O�p�̃�����
		Resource								_stagingResource;
		//GPUMem�ɃA�b�v���[�h���邽�߂̃������@�i���[�h�o�b�N�p�̃������͌p�����̃��\�[�X
		Resource								_uploadResource;

		D3D12_RANGE								_readRange;

		DescriptorHeap							_heap;

		D3D12_UNORDERED_ACCESS_VIEW_DESC		_unorderedAccessViewDesc;

		D3D12_SHADER_RESOURCE_VIEW_DESC			_shaderResourceViewDesc;

	public:

	private:

		HRESULT									CreateHeap(unsigned numElements, unsigned int nodeMask = 0);

	public:

		UnorderedAccessValue();

		virtual~UnorderedAccessValue();
		//���[�h�o�b�N�o�b�t�@�ƃA�b�v���[�h�o�b�t�@���쐬�B���ł�GPU�ɔz�u
		HRESULT									Create(unsigned int elementSize, unsigned int numElements, void* pBufferData);
		//�f�X�N���v�^�̍쐬
		HRESULT									CreateDescriptors(unsigned int elementSize, unsigned int numElements);

		HRESULT									CreateView(D3D12_UNORDERED_ACCESS_VIEW_DESC* uavDesc, D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorHandle);

		HRESULT									CreateView(D3D12_SHADER_RESOURCE_VIEW_DESC* srvDesc, D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorHandle);
		//���\�[�X���A�b�v���[�h�o�b�t�@�ɔz�u
		void									WriteToBuffer(unsigned int numElements, unsigned int elementSize, void* pBufferData);
		//�R�}���h���X�g���w�肵�Ă�邱�ƁB�񓯊��������A�Ń��\�[�X��GPU�z�u��������s
		void									AsyncWriteToBuffer(std::weak_ptr<K3D12::GraphicsCommandList> list, unsigned int numElements, unsigned int elementSize, void* pBufferData, K3D12::CommandQueue* queue = nullptr);
		//GPU��̏������[�h�o�b�N����(�ҋ@����)
		void									ReadBack();
		//�R�}���h���X�g���w�肵�Ă�邱�ƁB�񓯊��������A��GPU��̏������[�h�o�b�N��������s
		void									AsyncReadBack(std::weak_ptr<K3D12::GraphicsCommandList> list, K3D12::CommandQueue* queue = nullptr);
		//
		D3D12_CPU_DESCRIPTOR_HANDLE				GetSRVCPUHandle();
		//
		D3D12_CPU_DESCRIPTOR_HANDLE				GetUAVCPUHandle();
		//
		D3D12_GPU_DESCRIPTOR_HANDLE				GetSRVGPUHandle();
		//
		D3D12_GPU_DESCRIPTOR_HANDLE				GetUAVGPUHandle();

		void									Discard();

		ByteAddressBuffer						GetCounterResource()const;

		DescriptorHeap*							GetHeap();

		D3D12_UNORDERED_ACCESS_VIEW_DESC		GetUAVDesc();

		D3D12_SHADER_RESOURCE_VIEW_DESC			GetSRVDesc();

	};
}