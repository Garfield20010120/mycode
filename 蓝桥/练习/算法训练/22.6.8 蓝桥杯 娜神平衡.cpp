#include<iostream>
//22.6.8���ű� ����ƽ��
using namespace std;
#include<algorithm>
 
//����n������r
int n, r;
 
//��ѣ��������
int L[101] = { 0 }; int L_ = 0;
//�Ҷѣ��Ҷ�����
int R[101] = { 0 }; int R_ = 0;
 
//ԭʼ����
int date[101] = { 0 };
//��Ƕ�Ӧ����״̬����ѡ �� δѡ
bool ind[101] = { 0 };
 
//��ӡ���� - �޻س�
void print(int ii[], int n)
{
	for (int i = 1; i <= n; i++)
		cout << ii[i] << " ";
	return;
}
 
//�ݹ����
bool func(int L_R = 0)
{
	//��ֵ(����ֵ)
	int temp = L_R > 0 ? L_R : -L_R;
 
	//������ֵ�����������(ע��temp��Ҫȥ����ֵ��)
	if (temp > r)
	{
		return false;
	}
 
	//���������ݶ�������ʱ - �ʹ�����Խ�����
	if (L_ + R_ == n)
	{
		//���� - ����
		sort(L + 1, L + L_);
		sort(R + 1, R + R_);
 
		//Ѱ�ҵ�һ������
		for (int i = 1; i <= L_; i++)
		{
			if (date[1] == L[i])
			{
				print(L, L_);
				cout << endl;
				print(R, R_);
				return true;
			}
		}
		print(R, R_);
		cout << endl;
		print(L, L_);
		return true;
	}
 
	int i;
	for (i = 1; i <= n; i++)
	{
		//���״̬����û��ʹ��(false)
		if (!ind[i])
		{
			//���Ϊ��ʹ��(true)
			ind[i] = true;
 
			//�Ӹ����
			L[++L_] = date[i];
			//ѡ��֮���������
			if (func(L_R + date[i]))
				break;
 
			//ȡ��
			L[L_] = 0;
			L_--;
 
			//�Ӹ��Ҷ�
			R[++R_] = date[i];
			//ѡ��֮���������
			if (func(L_R - date[i]))
				break;
 
			//ȡ��
			R[R_] = 0;
			R_--;
 
			//�͵����·���
			ind[i] = false;
		}
	}
	//�����ߵ����i�ܵ�n������1��iû��n������0
	//�����ϲ���жϣ��ò㼰������ �ݹ��ܲ��ܱ����� ���е�Ԫ��
	return !(i == n + 1);
}
 
 
int main()
{
	cin >> n >> r;
 
	//��������
	for (int i = 1; i <= n; i++)
		cin >> date[i];
 
	//��ʼ�ݹ�
	func();
 
	return 0;
}
