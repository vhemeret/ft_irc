/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:27:09 by brhajji-          #+#    #+#             */
/*   Updated: 2023/02/07 19:15:10 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/User.hpp"

User::User(int fd) : fd(fd), _op(false)
{
}

User::~User()
{
}

//Getters

std::string User::getUsername(void){
	return this->username;
}

std::string User::getNickname(void){
	return this->nickname;
}

std::string User::getFullname(void){
	return this->fullname;
}

int	User::getFd(void)
{
	return this->fd;
}

bool User::getIRCOp(void)
{
	return this->_op;
}
// e_event User::getEventHooked(void) {
// 	return this->event_hooked;
// }

// Setters

void User::setUsername(std::string username){
	this->username = username;
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

void User::setIRCOp(bool state)
{
	this->_op = state;
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
