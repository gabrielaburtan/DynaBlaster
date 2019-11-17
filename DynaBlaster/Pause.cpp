#include "Pause.h"

Pause::Pause()
{
	int minutes = m_minutes;
	int seconds = m_seconds;
}

void Pause::displayClock()
{
	system("CLS");
	std::cout << std::setw(2) << m_minutes << " : " << std::setfill('0') << std::setw(2) << m_seconds << std::endl;
}

void Pause::pauseTimer()
{
	switch (_getch())
	{
	case 112:
		m_ok = true;
		break;
	case 114:
		m_ok = false;
		break;
	case 101:
		exit(0);
		break;
	default:
		break;
	}
}

void Pause::timer()
{
	while (!_kbhit() && m_ok == false)
	{
		if (m_seconds == 00) {

			m_minutes--;
			m_seconds = 60;
		}
		m_seconds--;
		if (m_minutes == 00 && m_seconds == 00)
			break;
		displayClock();
		Sleep(1000);
	}
	pauseTimer();

}