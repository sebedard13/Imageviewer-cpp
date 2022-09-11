#pragma once
class Index
{
public:
	Index(int minIncluded, int maxIncluded);

	Index(const Index& other) = default;
	Index(Index&& other) noexcept = default;
	Index& operator=(const Index& other) = default;
	Index& operator=(Index&& other) noexcept = default;
	~Index() = default;

	[[nodiscard]] int get() const;

	int operator()() const;

	int next();
	int previous();

private:
	void checkLoop();

	int min;
	int max;
	int current;
};

