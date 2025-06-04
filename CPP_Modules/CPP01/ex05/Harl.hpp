/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:51:14 by zblume            #+#    #+#             */
/*   Updated: 2025/04/14 10:51:40 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	
		typedef void (Harl::*ComplaintFunction)(void);
		struct ComplaintLevel
		{
			std::string level;
			ComplaintFunction function;
		};
		static ComplaintLevel complaintLevels[4];

	public:
		void complain(std::string level);
};

#endif
