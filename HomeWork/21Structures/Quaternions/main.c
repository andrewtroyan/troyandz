#include "QuaternionsOperations.h"

int main()
{
    Quaternion firstQuaternion, secondQuaternion, result;
    int answer;

    printf("Instruction\nEnter a quaternion in this order:\nREAL + i * IMAGINARY + j * IMAGINARY + k * IMAGINARY.\n\n"
    "Select an operation:\n1. Summarize\n2. Deduct\n3. Multiply\n4. Divide\n5. Mate\n\n");

    scanf("%d", &answer);
    system("clear");
    printf("Instruction\nEnter a quaternion number in this order:\nREAL + i * IMAGINARY + j * IMAGINARY + k * IMAGINARY.\n\n");
    switch(answer)
    {
    case 1:
        printf("Enter the first quaternion: ");
        enterQuaternion(&firstQuaternion);
        printf("Enter the second quaternion: ");
        enterQuaternion(&secondQuaternion);
        result = summarize(firstQuaternion, secondQuaternion);
        printf("The result: ");
        showQuaternion(result);
        break;
    case 2:
        printf("Enter the first quaternion: ");
        enterQuaternion(&firstQuaternion);
        printf("Enter the second quaternion: ");
        enterQuaternion(&secondQuaternion);
        result = deduct(firstQuaternion, secondQuaternion);
        printf("The result: ");
        showQuaternion(result);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        printf("Enter the quaternion number: ");
        enterQuaternion(&firstQuaternion);
        result = mate(firstQuaternion);
        printf("The result: ");
        showMatingQuaternion(result);
        break;
    default:
        fprintf(stderr, "Invalid value.\n");
        exit(1);
    }

    return 0;
}
