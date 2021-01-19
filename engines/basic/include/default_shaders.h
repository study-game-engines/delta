#ifndef DELTA_BASIC_DEFAULT_SHADERS_H
#define DELTA_BASIC_DEFAULT_SHADERS_H

#include "delta_core.h"

#include "shader_controls.h"
#include "shader_set.h"
#include "material.h"

namespace dbasic {

    class DefaultShaders : public ysObject {
    public:
        enum class CameraMode {
            Target,
            Flat
        };

    public:
        DefaultShaders();
        virtual ~DefaultShaders();

        ysError Initialize(ysDevice *device, ysRenderTarget *renderTarget, ysShaderProgram *shaderProgram, ysInputLayout *inputLayout);
        ysError Destroy();

        ShaderSet *GetShaderSet() { return &m_shaderSet; }

        ysError UseMaterial(Material *material);

        void ResetBrdfParameters();
        void SetBaseColor(const ysVector &color);
        void ResetBaseColor();

        void SetScale(float x = 1.0f, float y = 1.0f, float z = 1.0f);
        void SetTexOffset(float u, float v);
        void SetTexScale(float u, float v);

        void SetColorReplace(bool colorReplace);
        void SetLit(bool lit);
        void SetEmission(const ysVector &emission);
        void SetSpecularMix(float specularMix);
        void SetDiffuseMix(float diffuseMix);
        void SetMetallic(float metallic);
        void SetDiffuseRoughness(float diffuseRoughness);
        void SetSpecularRoughness(float specularRoughness);
        void SetSpecularPower(float power);
        void SetIncidentSpecular(float incidentSpecular);
        void SetFogNear(float fogNear);
        void SetFogFar(float fogFar);
        void SetFogColor(const ysVector &color);

        void SetObjectTransform(const ysMatrix &mat);
        void SetPositionOffset(const ysVector &position);

        void SetProjection(const ysMatrix &mat);
        void SetCameraView(const ysMatrix &mat);
        void SetEye(const ysVector &vec);

        ysError AddLight(const Light &light);
        void ResetLights();
        ysError SetAmbientLight(const ysVector4 &ambient);

        void SetCameraPosition(float x, float y);
        void SetCameraPosition(const ysVector &pos);
        ysVector GetCameraPosition() const;
        void GetCameraPosition(float *x, float *y) const;

        void SetCameraUp(const ysVector &up);
        ysVector GetCameraUp() const;

        void SetCameraTarget(const ysVector &target);
        ysVector GetCameraTarget() const { return m_cameraTarget; }

        void SetCameraMode(CameraMode mode);
        CameraMode GetCameraMode() const { return m_cameraMode; }

        void SetCameraAngle(float angle);
        float GetCameraAngle() const { return m_cameraAngle; }

        float GetCameraFov() const;
        void SetCameraFov(float fov);

        float GetCameraAspect() const;

        void SetCameraAltitude(float altitude);
        float GetCameraAltitude() const;

        void SetScreenDimensions(float width, float height);

        void CalculateCamera();

        void SetNearClip(float nearClip) { m_nearClip = nearClip; }
        float GetNearClip() const { return m_nearClip; }

        void SetFarClip(float farClip) { m_farClip = farClip; }
        float GetFarClip() const { return m_farClip; }

        void ConfigureFlags(int regularFlag, int riggedFlag);
        int GetRegularFlag() const;
        int GetRiggedFlag() const;

        void ConfigureImage(
            float scaleX, float scaleY, 
            float texOffsetU = 0.0f, float texOffsetV = 0.0f, 
            float texScaleU = 1.0f, float texScaleV = 1.0f);
        void ConfigureBox(float width, float height);
        void ConfigureAxis(const ysVector &position, const ysVector &direction, float length);
        void ConfigureModel(float scale);

    protected:
        ShaderScreenVariables m_shaderScreenVariables;
        ShaderObjectVariables m_shaderObjectVariables;
        LightingControls m_lightingControls;
        int m_lightCount;

        float m_cameraAngle;
        float m_cameraFov;

        float m_nearClip;
        float m_farClip;

        ysVector m_cameraPosition;
        ysVector m_cameraTarget;
        ysVector m_cameraUp;

        float m_screenWidth;
        float m_screenHeight;

    protected:
        ShaderSet m_shaderSet;
        CameraMode m_cameraMode;
    };

} /* namespace dbasic */

#endif /* DELTA_BASIC_DEFAULT_SHADERS_H */
