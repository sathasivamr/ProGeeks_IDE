-- phpMyAdmin SQL Dump
-- version 4.4.7
-- http://www.phpmyadmin.net
--
-- Host: localhost:3306
-- Generation Time: Sep 06, 2015 at 11:39 AM
-- Server version: 5.6.26
-- PHP Version: 5.5.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `progeeks`
--

-- --------------------------------------------------------

--
-- Table structure for table `question`
--

CREATE TABLE IF NOT EXISTS `question` (
  `Question_Id` int(100) NOT NULL,
  `Question_Name` varchar(200) NOT NULL,
  `Question_Problem` longtext NOT NULL,
  `Question_Input` varchar(500) NOT NULL,
  `Question_Output` varchar(500) NOT NULL,
  `Question_Inputformat` varchar(500) DEFAULT NULL,
  `Question_Outputformat` varchar(500) DEFAULT NULL,
  `Question_Explanation` varchar(500) DEFAULT NULL,
  `Question_Range` varchar(300) NOT NULL,
  `Question_Testcase` int(100) NOT NULL,
  `Question_I1` varchar(500) DEFAULT NULL,
  `Question_I2` varchar(500) DEFAULT NULL,
  `Question_I3` varchar(500) DEFAULT NULL,
  `Question_I4` varchar(500) DEFAULT NULL,
  `Question_I5` varchar(500) DEFAULT NULL,
  `Question_I6` varchar(500) DEFAULT NULL,
  `Question_I7` varchar(500) DEFAULT NULL,
  `Question_I8` varchar(500) DEFAULT NULL,
  `Question_I9` varchar(500) DEFAULT NULL,