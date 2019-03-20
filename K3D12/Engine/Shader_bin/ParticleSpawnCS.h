#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer cb0
// {
//
//   float gametime;                    // Offset:    0 Size:     4
//   float deltaTime;                   // Offset:    4 Size:     4 [unused]
//   uint spawnerCount;                 // Offset:    8 Size:     4
//   float pad;                         // Offset:   12 Size:     4 [unused]
//
// }
//
// Resource bind info for spawnArgs
// {
//
//   struct SpawnData
//   {
//       
//       float3 forward;                // Offset:    0
//       float colorSamplingV;          // Offset:   12
//       float4 position;               // Offset:   16
//       float initialSpeedFactor;      // Offset:   32
//       float reductionRate;           // Offset:   36
//       float speedMag;                // Offset:   40
//       float lengthMag;               // Offset:   44
//
//   } $Element;                        // Offset:    0 Size:    48
//
// }
//
// Resource bind info for reservedSlots
// {
//
//   uint $Element;                     // Offset:    0 Size:     4
//
// }
//
// Resource bind info for instanceProperties
// {
//
//   struct InstanceData
//   {
//       
//       float4 position;               // Offset:    0
//       float3 forward;                // Offset:   16
//       float initialSpeedFactor;      // Offset:   28
//       float reductionRate;           // Offset:   32
//       float speedMag;                // Offset:   36
//       float lengthMag;               // Offset:   40
//       float spawnTime;               // Offset:   44
//       float3 reserved;               // Offset:   48
//       float colorSamplingV;          // Offset:   60
//
//   } $Element;                        // Offset:    0 Size:    64
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// spawnArgs                         texture  struct         r/o             t0      1 
// reservedSlots                         UAV  struct     consume             u0      1 
// instanceProperties                    UAV  struct         r/w             u2      1 
// cb0                               cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[1], immediateIndexed
dcl_resource_structured t0, 48
dcl_uav_structured u0, 4
dcl_uav_structured u2, 64
dcl_input vThreadID.x
dcl_temps 4
dcl_thread_group 256, 1, 1
ult r0.x, vThreadID.x, cb0[0].z
if_nz r0.x
  imm_atomic_consume r0.x, u0
  ld_structured_indexable(structured_buffer, stride=4)(mixed,mixed,mixed,mixed) r0.x, r0.x, l(0), u0.xxxx
  ld_structured_indexable(structured_buffer, stride=48)(mixed,mixed,mixed,mixed) r1.xyzw, vThreadID.x, l(16), t0.xyzw
  store_structured u2.xyzw, r0.x, l(0), r1.xyzw
  ld_structured_indexable(structured_buffer, stride=48)(mixed,mixed,mixed,mixed) r1.xyzw, vThreadID.x, l(0), t0.xyzw
  ld_structured_indexable(structured_buffer, stride=48)(mixed,mixed,mixed,mixed) r2.xyzw, vThreadID.x, l(32), t0.xyzw
  mov r3.xyz, r1.xyzx
  mov r3.w, r2.x
  store_structured u2.xyzw, r0.x, l(16), r3.xyzw
  store_structured u2.xyz, r0.x, l(32), r2.yzwy
  store_structured u2.x, r0.x, l(60), r1.w
  store_structured u2.x, r0.x, l(44), cb0[0].x
endif 
ret 
// Approximately 16 instruction slots used
#endif

const BYTE _ParticleSpawnCS_bin[] =
{
     68,  88,  66,  67,  23,  72, 
     43,  91, 120, 163,  53, 229, 
     13, 235, 117,  10, 140, 200, 
    253, 177,   1,   0,   0,   0, 
    108,   8,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    116,   5,   0,   0, 132,   5, 
      0,   0, 148,   5,   0,   0, 
    208,   7,   0,   0,  82,  68, 
     69,  70,  56,   5,   0,   0, 
      4,   0,   0,   0, 236,   0, 
      0,   0,   4,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  67,   0,   1,   0,   0, 
     16,   5,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    188,   0,   0,   0,   5,   0, 
      0,   0,   6,   0,   0,   0, 
      1,   0,   0,   0,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 198,   0,   0,   0, 
     10,   0,   0,   0,   6,   0, 
      0,   0,   1,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 212,   0, 
      0,   0,   6,   0,   0,   0, 
      6,   0,   0,   0,   1,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    231,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 115, 112,  97, 119, 
    110,  65, 114, 103, 115,   0, 
    114, 101, 115, 101, 114, 118, 
    101, 100,  83, 108, 111, 116, 
    115,   0, 105, 110, 115, 116, 
     97, 110,  99, 101,  80, 114, 
    111, 112, 101, 114, 116, 105, 
    101, 115,   0,  99,  98,  48, 
      0, 171, 231,   0,   0,   0, 
      4,   0,   0,   0,  76,   1, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 188,   0,   0,   0, 
      1,   0,   0,   0, 104,   2, 
      0,   0,  48,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 198,   0,   0,   0, 
      1,   0,   0,   0, 236,   3, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 212,   0,   0,   0, 
      1,   0,   0,   0,  56,   4, 
      0,   0,  64,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 236,   1,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    252,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     32,   2,   0,   0,   4,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 252,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  42,   2, 
      0,   0,   8,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0,  64,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 100,   2,   0,   0, 
     12,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    252,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    103,  97, 109, 101, 116, 105, 
    109, 101,   0, 102, 108, 111, 
     97, 116,   0, 171,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    245,   1,   0,   0, 100, 101, 
    108, 116,  97,  84, 105, 109, 
    101,   0, 115, 112,  97, 119, 
    110, 101, 114,  67, 111, 117, 
    110, 116,   0, 100, 119, 111, 
    114, 100,   0, 171, 171, 171, 
      0,   0,  19,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  55,   2,   0,   0, 
    112,  97, 100,   0, 144,   2, 
      0,   0,   0,   0,   0,   0, 
     48,   0,   0,   0,   2,   0, 
      0,   0, 200,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  36,  69, 108, 101, 
    109, 101, 110, 116,   0,  83, 
    112,  97, 119, 110,  68,  97, 
    116,  97,   0, 102, 111, 114, 
    119,  97, 114, 100,   0, 102, 
    108, 111,  97, 116,  51,   0, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 171,   2, 
      0,   0,  99, 111, 108, 111, 
    114,  83,  97, 109, 112, 108, 
    105, 110, 103,  86,   0, 171, 
      0,   0,   3,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 245,   1,   0,   0, 
    112, 111, 115, 105, 116, 105, 
    111, 110,   0, 102, 108, 111, 
     97, 116,  52,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     21,   3,   0,   0, 105, 110, 
    105, 116, 105,  97, 108,  83, 
    112, 101, 101, 100,  70,  97, 
     99, 116, 111, 114,   0, 114, 
    101, 100, 117,  99, 116, 105, 
    111, 110,  82,  97, 116, 101, 
      0, 115, 112, 101, 101, 100, 
     77,  97, 103,   0, 108, 101, 
    110, 103, 116, 104,  77,  97, 
    103,   0, 163,   2,   0,   0, 
    180,   2,   0,   0,   0,   0, 
      0,   0, 216,   2,   0,   0, 
    232,   2,   0,   0,  12,   0, 
      0,   0,  12,   3,   0,   0, 
     28,   3,   0,   0,  16,   0, 
      0,   0,  64,   3,   0,   0, 
    232,   2,   0,   0,  32,   0, 
      0,   0,  83,   3,   0,   0, 
    232,   2,   0,   0,  36,   0, 
      0,   0,  97,   3,   0,   0, 
    232,   2,   0,   0,  40,   0, 
      0,   0, 106,   3,   0,   0, 
    232,   2,   0,   0,  44,   0, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  12,   0,   0,   0, 
      7,   0, 116,   3,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 153,   2, 
      0,   0, 144,   2,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
     20,   4,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      0,   0,  19,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  55,   2,   0,   0, 
    144,   2,   0,   0,   0,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0, 236,   4, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  73, 110, 
    115, 116,  97, 110,  99, 101, 
     68,  97, 116,  97,   0, 115, 
    112,  97, 119, 110,  84, 105, 
    109, 101,   0, 114, 101, 115, 
    101, 114, 118, 101, 100,   0, 
     12,   3,   0,   0,  28,   3, 
      0,   0,   0,   0,   0,   0, 
    163,   2,   0,   0, 180,   2, 
      0,   0,  16,   0,   0,   0, 
     64,   3,   0,   0, 232,   2, 
      0,   0,  28,   0,   0,   0, 
     83,   3,   0,   0, 232,   2, 
      0,   0,  32,   0,   0,   0, 
     97,   3,   0,   0, 232,   2, 
      0,   0,  36,   0,   0,   0, 
    106,   3,   0,   0, 232,   2, 
      0,   0,  40,   0,   0,   0, 
    109,   4,   0,   0, 232,   2, 
      0,   0,  44,   0,   0,   0, 
    119,   4,   0,   0, 180,   2, 
      0,   0,  48,   0,   0,   0, 
    216,   2,   0,   0, 232,   2, 
      0,   0,  60,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
     16,   0,   0,   0,   9,   0, 
    128,   4,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  96,   4,   0,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  49, 
     48,  46,  49,   0,  73,  83, 
     71,  78,   8,   0,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  79,  83,  71,  78, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     83,  72,  69,  88,  52,   2, 
      0,   0,  80,   0,   5,   0, 
    141,   0,   0,   0, 106,   8, 
      0,   1,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    162,   0,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     48,   0,   0,   0, 158,   0, 
      0,   4,   0, 224,  17,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0, 158,   0,   0,   4, 
      0, 224,  17,   0,   2,   0, 
      0,   0,  64,   0,   0,   0, 
     95,   0,   0,   2,  18,   0, 
      2,   0, 104,   0,   0,   2, 
      4,   0,   0,   0, 155,   0, 
      0,   4,   0,   1,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  79,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,   2,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   0,   0,   0,   0, 
    179,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
      0, 224,  17,   0,   0,   0, 
      0,   0, 167,   0,   0, 139, 
      2,  35,   0, 128, 131, 153, 
     25,   0,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 224,  17,   0, 
      0,   0,   0,   0, 167,   0, 
      0, 138,   2, 131,   1, 128, 
    131, 153,  25,   0, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,   2,   0,   1,  64, 
      0,   0,  16,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0, 168,   0,   0,   9, 
    242, 224,  17,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0, 167,   0,   0, 138, 
      2, 131,   1, 128, 131, 153, 
     25,   0, 242,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
      2,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
    167,   0,   0, 138,   2, 131, 
      1, 128, 131, 153,  25,   0, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,   2,   0, 
      1,  64,   0,   0,  32,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 114,   0,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0, 168,   0,   0,   9, 
    242, 224,  17,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,  16,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0, 168,   0,   0,   9, 
    114, 224,  17,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,  32,   0,   0,   0, 
    150,   7,  16,   0,   2,   0, 
      0,   0, 168,   0,   0,   9, 
     18, 224,  17,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,  60,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0, 168,   0,   0,  10, 
     18, 224,  17,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,  44,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     21,   0,   0,   1,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0,  16,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0
};