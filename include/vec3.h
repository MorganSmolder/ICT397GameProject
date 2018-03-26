#pragma once
class vec3
{
public:

	vec3()
	{
		this->m_x = 0;
		this->m_y = 0;
		this->m_z = 0;
	}

	vec3(float x, float y, float z)
	{
		this->m_x = x;
		this->m_y = y;
		this->m_z = z;
	}

	float x() const{
		return m_x;
	}

	float y() const{
		return m_y;
	}

	float z() const{
		return m_z;
	}

	float sx(float nx){
		this->m_x = nx;
		return m_x;
	}

	float sy(float ny){
		this->m_y = ny;
		return m_y;
	}

	float sz(float nz){
		this->m_z = nz;
		return m_z;
	}

private:
	float m_x, m_y, m_z;
};

