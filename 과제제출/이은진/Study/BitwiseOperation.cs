# include <iostream>

using namespace std;

int arr[101];

int main()
{
    int N;
    cin >> N;

    // 배열 정보 입력받기
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 비트 연산을 통해 모든 부분집합 구하기
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j];
            }
        }
        cout << '\n';
    }

    return 0;
}

