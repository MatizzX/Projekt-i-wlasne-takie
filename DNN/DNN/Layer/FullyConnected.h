#pragma once

#include <Eigen/Core>
#include <vector>
#include <stdexcept>
#include "../Config.h"
#include "../Layer.h"
#include "../Utils/Random.h"

template<typename Activation>

class FullyConnected : public Layer
{

private:
	typedef Eigen::Matrix< Scalar, Eigen::Dynamic, Eigen::Dynamic > Matrix;
	typedef Eigen::Matrix< Scalar, Eigen::Dynamic, 1 > Vector;

	Matrix m_weight;
	Vector m_bias;
	Matrix m_dw; //derivative / weight
	Vector m_db; // -||- / bias
	Matrix m_z; //applying bias to multiplicated weights
	Matrix m_a; //applying activation function to z
	Matrix m_din; //derivative of input

public:
	FullyConnected(const int in_size, const int out_size) :
		Layer(int_size, out_size) {}

	void init(const Scalar& mu, const Scalar& sigma, RNG& rng)
	{
		m_weight.resize(this->m_in_size, this->m_out_size);
		m_bias.resize(this->m_out_size);
		m_dw.resize(this->m_in_size, this->m_out_size);
		m_db.resize(this->m_out_size);

		internal::set_normal_random(m_wieght.date(), m_weight.size(), rng, mu, sigma);
		internal::set_normal_random(m_bias.date(), m_bias.size(), rng, mu, sigma);
	}

	void forward(const Matrix& prev_layer_data)
	{
		const int nobs = prev_layer_data.col(); //numbers of observations/colums of input
		// z=w' * in + bias
		m_z.resize(this->m_out_size, nobs);
		m_z.noalias() = m_weight.transpose() * prev_layer_data;
		m_z.colwise() += bias;

		//applying activation function
		m_a.resize(this->m_out_size, nobs);
		Activation::activate(m_z, m_a); //applying actication function to m_z then storing it in m_a

	}

	const Matrix& output() const
	{
		return m_a;
	}

};
