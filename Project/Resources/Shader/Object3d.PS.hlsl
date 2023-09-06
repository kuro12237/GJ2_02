#include "Object3d.hlsli"

struct Material {
	float32_t4 color;
	int32_t enableLighting;
	float32_t4x4 uvTransform;
};

struct DirectionLight {
	float32_t4 color;//ライトの色
	float32_t3 direction;//ライトの向き
	float intensity;//輝度
};

ConstantBuffer<Material> gMaterial : register(b0);
ConstantBuffer<DirectionLight> gDirectionalLight : register(b1);
Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

struct PixelShaderOutput {
	float32_t4 color : SV_TARGET0;
	float32_t depth : SV_TARGET1;
};

PixelShaderOutput main(VertexShaderOutput input) {
	PixelShaderOutput output;
	float4 transformUV = mul(float32_t4(input.texcoord, 0.0f, 1.0f), gMaterial.uvTransform);
	float32_t4 textureColor = gTexture.Sample(gSampler, transformUV.xy);
	output.color = gMaterial.color * textureColor;
	if (gMaterial.enableLighting != 0) {
		float NdotL = dot(normalize(input.normal), -gDirectionalLight.direction);
		float cos = pow(NdotL * 0.5f + 0.5f, 2.0f);
		output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
	}
	else {
		output.color = gMaterial.color * textureColor;
	}

	//線形深度
	output.depth = input.depth.x;

	return output;
}