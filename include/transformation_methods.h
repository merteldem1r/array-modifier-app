//
// Created by Mert on 21.12.2024.
//

#ifndef TRANSFORMATION_METHODS_H
#define TRANSFORMATION_METHODS_H
#include <array.h>

#define REVERSE 13
#define LEFT_SHIFT 14
#define RIGHT_SHIFT 15
#define ROTATE 16
#define SCALE 17
#define NORMALIZE 18

void TransformationMethodOperations(const struct Array *arr, int operation);

// Transformations Methods
void Reverse(const struct Array *arr);

void LeftShift(const struct Array *arr);

void RightShift(const struct Array *arr);

void Rotate(const struct Array *arr, int k);


#endif //TRANSFORMATION_METHODS_H
