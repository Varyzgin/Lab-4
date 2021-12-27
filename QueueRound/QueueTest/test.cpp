#include "pch.h"
#include "..\QueueRound\TQueue.h"

using namespace std;
TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}
TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}
TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(TQueue<int> q1 = q);
}
TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	int size = 4;
	TQueue<int> q(size);
	for (int i = 0; i < size; i++)
		q.Push(5);
	TQueue<int> q1 = q;
	ASSERT_TRUE(q1 == q);
}
TEST(TQueue, copied_queue_has_its_own_memory)
{
	TQueue<int> q(4);
	for (int i = 0; i < 4; i++)
		q.Push(i);
	TQueue<int> q1 = q;
	q1.Clear();
	for (int i = 0; i < 4; i++)
		q1.Push(i + 1);
	for (int i = 0; i < 4; i++)
		ASSERT_TRUE(q.Pop() != q1.Pop());
}
TEST(TQueue, can_assign)
{
	TQueue<int> q1(4);
	for (int i = 0; i < 4; i++) q1.Push(i);
	TQueue<int> q2(5);
	q2 = q1;
	ASSERT_TRUE(q2 == q1);
}
TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++) q.Push(i);
	q = q;
	ASSERT_TRUE(q == q);
}
TEST(TQueue, queues_with_different_Maxsizes_are_not_equal)
{
	TQueue<int> q1(4);
	TQueue<int> q2(5);
	ASSERT_TRUE(q1 != q2);
}
TEST(TQueue, can_push)
{
	TQueue<int> q(4);
	ASSERT_NO_THROW(q.Push(1));
}
TEST(TQueue, can_pop)
{
	TQueue<int> q(4);
	q.Push(1);
	ASSERT_NO_THROW(q.Pop() == 1);
}
TEST(TQueue, cant_push_to_a_full_queue)
{
	int size = 10;
	TQueue<int> q(size);
	for (int i = 0; i < size; i++) q.Push(i);
	ASSERT_ANY_THROW(q.Push(1000));
}
TEST(TQueue, cant_pop_from_an_empty_queue)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Pop());
}
TEST(TQueue, cleared_queue_is_empty)
{
	TQueue<int> q(4);
	for (int i = 0; i < 4; i++) q.Push(4);
	q.Clear();
	ASSERT_TRUE(q.Empty());
}