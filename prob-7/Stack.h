//
// Created by alpat on 20.04.2023.
//

#pragma once
template<typename ValType>
class IStack
{
public:
	virtual void Push(const ValType& val) = 0;
	virtual ValType Pop() = 0;
	virtual ValType& GetTop() = 0;
	virtual bool IsEmpty() const = 0;
};


template<typename ArrType, typename ValType>
class Stack : public  IStack<ValType>
{
public:
	void Push(const ValType& val) override
	{
		m_data.push_back(val);
	}

	ValType Pop() override
	{
		auto val = GetTop();
		m_data.remove(m_data.GetSize()-1);

		return val;
	}

	ValType& GetTop() override
	{
		return m_data[m_data.GetSize()-1];
	}

	[[nodiscard]] bool IsEmpty() const override
	{
		return !m_data.GetSize();
	}
private:
	ArrType m_data;
};