/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:44:00 by zblume            #+#    #+#             */
/*   Updated: 2025/04/09 10:50:33 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string& getType(void) const;
		void setType(std::string type);
};

#endif
