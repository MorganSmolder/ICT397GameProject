#pragma once
class vec2
{
public:
	float m_x, m_y;
	vec2(float x, float y) { this->m_x = x; this->m_y = y; };
	float x() {
		return m_x;
	}
	float y() {
		return m_y;
	}
	vec2() {
		m_x = 0;
		m_y = 0;
	}
};

