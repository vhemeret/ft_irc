/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:27:09 by brhajji-          #+#    #+#             */
/*   Updated: 2023/02/10 07:10:11 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/User.hpp"

User::User(int fd) : fd(fd), _op(false), _i(true), _w(false) , lastPong(std::time(0)), lastPing(std::time(0)), dead(false)
{
}

User::~User(){
	if (this->fd > 0)
		close(this->fd);
}

//Getters

std::string User::getUsername(void){
	return this->username;
}

std::string User::getNickname(void){
	return this->nickname;
}

bool User::getDead(void){
	return this->dead;
}

std::string User::getFullname(void){
	return this->fullname;
}

int	User::getFd(void)
{
	return this->fd;
}

time_t	User::getPong(void)
{
	return this->lastPong;
}

time_t	User::getPing(void)
{
	return this->lastPong;
}

bool User::getIRCOp(void)
{
	return this->_op;
}

bool User::get_i(void) const
{
	return this->_i;
}

bool User::get_w(void) const
{
	return this->_w;
}

std::string	User::getMode(void) const
{
	std::string mode = "";

	if (this->_op == true)
		mode += "o";
	if (this->_i == true)
		mode += "i";
	if (this->_w == true)
		mode += "w";
	return (mode);
}


// Setters

void User::setDead(bool dead)
{
	this->dead = dead;
}

void User::setUsername(std::string username){
	this->username = username;
	return ;
}

void User::setPong(time_t time){
	this->lastPong = time;
	return ;
}

void User::setPing(time_t time){
	this->lastPing = time;
	return ;
}

void User::setFullname(std::string fullname){
	this->fullname = fullname;
	return ;
}

void User::setNickname(std::string nickname){
	this->nickname = nickname;
	return ;
}

void User::setMode(std::string mode, bool state)
{
	if (!mode.empty())
	{
		if (mode.find("+w") != std::string::npos)
			this->_w = state;
		else if (mode.find("+i") != std::string::npos)
			this->_i = state;
		else if (mode.find("IRCOP") != std::string::npos)
			this->_op = state;
		else if (mode.find("-i") != std::string::npos)
			this->_i = state;
		else if (mode.find("-w") != std::string::npos)
			this->_w = state;
		else if (mode.find("-o") != std::string::npos)
			this->_op = state;
	}
	return ;
}

// Specifics methods

void User::writeMessage(std::string message){
	message += "\r\n";
	write(this->fd, message.c_str(), message.length());
}

// void User::incrEventHooked(void){
// 	this->event_hooked = static_cast<e_event>(this->event_hooked + 1);
// }
