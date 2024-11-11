
/*!
 ************************************************************************
 * \file quant.h
 *
 * \brief
 *    definitions for quantization functions
 *
 * \author
 *
 ************************************************************************
 */

#ifndef _QUANT_H_
#define _QUANT_H_

// exported variables
static const int dequant_coef8[6][8][8] = {{{20, 19, 25, 19, 20, 19, 25, 19},
                                            {19, 18, 24, 18, 19, 18, 24, 18},
                                            {25, 24, 32, 24, 25, 24, 32, 24},
                                            {19, 18, 24, 18, 19, 18, 24, 18},
                                            {20, 19, 25, 19, 20, 19, 25, 19},
                                            {19, 18, 24, 18, 19, 18, 24, 18},
                                            {25, 24, 32, 24, 25, 24, 32, 24},
                                            {19, 18, 24, 18, 19, 18, 24, 18}},
                                           {{22, 21, 28, 21, 22, 21, 28, 21},
                                            {21, 19, 26, 19, 21, 19, 26, 19},
                                            {28, 26, 35, 26, 28, 26, 35, 26},
                                            {21, 19, 26, 19, 21, 19, 26, 19},
                                            {22, 21, 28, 21, 22, 21, 28, 21},
                                            {21, 19, 26, 19, 21, 19, 26, 19},
                                            {28, 26, 35, 26, 28, 26, 35, 26},
                                            {21, 19, 26, 19, 21, 19, 26, 19}},
                                           {{26, 24, 33, 24, 26, 24, 33, 24},
                                            {24, 23, 31, 23, 24, 23, 31, 23},
                                            {33, 31, 42, 31, 33, 31, 42, 31},
                                            {24, 23, 31, 23, 24, 23, 31, 23},
                                            {26, 24, 33, 24, 26, 24, 33, 24},
                                            {24, 23, 31, 23, 24, 23, 31, 23},
                                            {33, 31, 42, 31, 33, 31, 42, 31},
                                            {24, 23, 31, 23, 24, 23, 31, 23}},
                                           {{28, 26, 35, 26, 28, 26, 35, 26},
                                            {26, 25, 33, 25, 26, 25, 33, 25},
                                            {35, 33, 45, 33, 35, 33, 45, 33},
                                            {26, 25, 33, 25, 26, 25, 33, 25},
                                            {28, 26, 35, 26, 28, 26, 35, 26},
                                            {26, 25, 33, 25, 26, 25, 33, 25},
                                            {35, 33, 45, 33, 35, 33, 45, 33},
                                            {26, 25, 33, 25, 26, 25, 33, 25}},
                                           {{32, 30, 40, 30, 32, 30, 40, 30},
                                            {30, 28, 38, 28, 30, 28, 38, 28},
                                            {40, 38, 51, 38, 40, 38, 51, 38},
                                            {30, 28, 38, 28, 30, 28, 38, 28},
                                            {32, 30, 40, 30, 32, 30, 40, 30},
                                            {30, 28, 38, 28, 30, 28, 38, 28},
                                            {40, 38, 51, 38, 40, 38, 51, 38},
                                            {30, 28, 38, 28, 30, 28, 38, 28}},
                                           {{36, 34, 46, 34, 36, 34, 46, 34},
                                            {34, 32, 43, 32, 34, 32, 43, 32},
                                            {46, 43, 58, 43, 46, 43, 58, 43},
                                            {34, 32, 43, 32, 34, 32, 43, 32},
                                            {36, 34, 46, 34, 36, 34, 46, 34},
                                            {34, 32, 43, 32, 34, 32, 43, 32},
                                            {46, 43, 58, 43, 46, 43, 58, 43},
                                            {34, 32, 43, 32, 34, 32, 43, 32}}};

//! Dequantization coefficients
static const int dequant_coef[6][4][4] = {
    {{10, 13, 10, 13}, {13, 16, 13, 16}, {10, 13, 10, 13}, {13, 16, 13, 16}},
    {{11, 14, 11, 14}, {14, 18, 14, 18}, {11, 14, 11, 14}, {14, 18, 14, 18}},
    {{13, 16, 13, 16}, {16, 20, 16, 20}, {13, 16, 13, 16}, {16, 20, 16, 20}},
    {{14, 18, 14, 18}, {18, 23, 18, 23}, {14, 18, 14, 18}, {18, 23, 18, 23}},
    {{16, 20, 16, 20}, {20, 25, 20, 25}, {16, 20, 16, 20}, {20, 25, 20, 25}},
    {{18, 23, 18, 23}, {23, 29, 23, 29}, {18, 23, 18, 23}, {23, 29, 23, 29}}};

static const int quant_coef[6][4][4] = {{{13107, 8066, 13107, 8066},
                                         {8066, 5243, 8066, 5243},
                                         {13107, 8066, 13107, 8066},
                                         {8066, 5243, 8066, 5243}},
                                        {{11916, 7490, 11916, 7490},
                                         {7490, 4660, 7490, 4660},
                                         {11916, 7490, 11916, 7490},
                                         {7490, 4660, 7490, 4660}},
                                        {{10082, 6554, 10082, 6554},
                                         {6554, 4194, 6554, 4194},
                                         {10082, 6554, 10082, 6554},
                                         {6554, 4194, 6554, 4194}},
                                        {{9362, 5825, 9362, 5825},
                                         {5825, 3647, 5825, 3647},
                                         {9362, 5825, 9362, 5825},
                                         {5825, 3647, 5825, 3647}},
                                        {{8192, 5243, 8192, 5243},
                                         {5243, 3355, 5243, 3355},
                                         {8192, 5243, 8192, 5243},
                                         {5243, 3355, 5243, 3355}},
                                        {{7282, 4559, 7282, 4559},
                                         {4559, 2893, 4559, 2893},
                                         {7282, 4559, 7282, 4559},
                                         {4559, 2893, 4559, 2893}}};

// SP decoding parameter (EQ. 8-425)
static const int A[4][4] = {
    {16, 20, 16, 20}, {20, 25, 20, 25}, {16, 20, 16, 20}, {20, 25, 20, 25}};

// exported functions
// quantization initialization
extern void init_qp_process(VideoParameters *p_Vid);
extern void free_qp_matrices(VideoParameters *p_Vid);

// For Q-matrix
extern void assign_quant_params(Slice *currslice);
extern void CalculateQuant4x4Param(Slice *currslice);
extern void CalculateQuant8x8Param(Slice *currslice);

#endif
