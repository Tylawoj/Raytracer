#include "ThreadManager.h"

bool ThreadManager::Init(glm::ivec2 _windowSize)
{
    m_threadsAmount = std::thread::hardware_concurrency();

    if (m_threadsAmount == 0)
    {
        // most likely C++11 is not supported or CPU information is impossible to be obtained
		return -1;
    }

    int xInterval = _windowSize.x / m_threadsAmount;
    int xRemainder = _windowSize.x % m_threadsAmount;

    for (int i = 0, sum = 0; i < m_threadsAmount; i++)
    {
        sum += xInterval;
        m_intervals.push_back(sum);
    }

    if (xRemainder > 0)
    {
        for (int x = 0; x < xRemainder; x++)
        {
            m_intervals.at(x) += 1;
        }
    }

    m_percentsDone = std::vector<int>(m_threadsAmount, 0);

    return true;
}

unsigned int ThreadManager::GetThreadsAmount()
{
    return m_threadsAmount;
}

std::vector<int> ThreadManager::GetIntervals()
{
    return m_intervals;
}

int ThreadManager::GetPercentDone(int _threadId)
{
    return m_percentsDone.at(_threadId);
}

void ThreadManager::SetPercentDone(int _threadId, int _percentDone)
{
    m_percentsDone.at(_threadId) = _percentDone;
}

