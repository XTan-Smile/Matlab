/* This is a c++ version of resume of Xiao Tan
 * 
 * class PersonInfo
 *   private class School
 *   private clsdd Experience
 * 
 * Last modified: June 1, 2015
 * 
 * (c) Margaret Tan, Duke University
 */
#ifndef __RESUME_H__
#define __RESUME_H__

#include <iostream>
#include <string>
#include <vector>
#include "outputColor.h"

using std::string;
using std::vector;

class PersonInfo {
private:
  string name;
  string email;
  string phone;
  string language;

  class Publication {
  private: 
    string title[3];
    string author[3];
    string journal[3];
    string append[3];
  public: 
    Publication() {
      title[2] = "EMD-based electrocardiogram delineation for a wearable low-power ECG monitoring device";
      title[1] = "Real-Time Baseline Wander Removal in ECG Signal Based on Weighted Local Linear Regression Smoothing";
      title[0] = "A Bluetooth Low Energy Approach for Monitoring Electrocardiography and Respiration";

      author[2] = "X. Tan, X. Chen, X. Hu, R. Ren, B. Zhou, Z. Fang, S. Xia";
      author[1] = "X. Tan, X. Chen, X. Hu, R. Ren, B. Zhou, Z. Fang, S. Xia";
      author[0] = "B. Zhou, X. Chen, X. Hu, R. Ren, X. Tan, Z. Fang, S. Xia";

      journal[2] = "Canadian Journal of Electrical and Computer Engineering";
      journal[1] = "The Proceedings of IEEE International Conference on Information and Automation (ICIA)";
      journal[0] = "The Proceedings of IEEE International Conference on e-Health Networking, Applications and Services (Healthcom 2013)";

      append[2] = "vol. 37(4), pp. 212-221, 2014.";
      append[1] = "Yinchuan, China, 2013";
      append[0] = "Lisbon, Portugal, 2013";
    }
    void printPublication (const int num = 3) {
      std::cout << CYAN;
      std::cout << "PUBLICATION" << std::endl;
      std::cout << RESET;
      for (int i = num-1; i >= 0; i--) {
		
	std::cout << " - ";
	std::cout << author[i] << ", "; 
		 
	std::cout << YELLOW;
	std::cout << "\"" 
		  << title[i]  << "\"";
	std::cout << RESET;
	std::cout << ", "
		  << journal[i] << ", "
		  << append[i] << std::endl;
      }
      std::cout << std::endl;
    }
    ~Publication() {}
  };

  class School {
  private:
      string schools[3];
      string locations[3];
      string major[3];
      string gradDate[3];
  public:
    School() {
    schools[2] = "Duke University (Duke)";
    schools[1] = "Chinese Academy of Sciences (CAS)";
    schools[0] = "Wuhan University of Technology (WUT)";

    locations[2] = "Durham NC, USA";
    locations[1] = "Beijing, China";
    locations[0] = "Wuhan, China";

    major[2] = "Master of Science in Electrical and Computer Engineering";
    major[1] = "Master of Engineering in Microelectronics and Solid State Electronics";
    major[0] = "Bachelor of Engineering in Communication Engineering (with extinct)";

    gradDate[2] = "May 2016";
    gradDate[1] = "July 2014";
    gradDate[0] = "June 2011";
  }
    // list attended schools
    void printSchool(const int num = 3) {
      // bold yellow
      std::cout << CYAN;
      std::cout << "EDUCATION" << std::endl;
      std::cout << RESET;      
      for (int i = num-1; i >= 0; i--) {
        std::cout << YELLOW;
        std::cout << schools[i] << ", " 
  		  << locations[i] << "    " 
  		  << gradDate[i] << std::endl;
        std::cout << RESET;
        std::cout << " - " << major[i] << std::endl;
      }
      std::cout << std::endl;
    }
    ~School() {}
  };

  class Experience {
  private:
    string exper[5];
    string timePeriod[5];
    string locations[5];
    vector<vector<string> > items;
  public:
    Experience() {
      exper[5] = "Compressive Sensing and Related Applications"
	exper[4] = ""
      exper[3] = "Amazon Picking Challenge";
      exper[2] = "Machine Learning Algorithm Design";
      exper[1] = "Electrocardiogram (ECG) Signal Detection on Android Platform";
      exper[0] = "Electrocardiogram (ECG) Signal Analysis";

      timePeriod[5] = "June 2015 - present";
      timePeriod[4] = "May 2015 - Aug 2015";
      timePeriod[3] = "Jan 2015 - May 2015";
      timePeriod[2] = "Sept 2014 - May 2015";
      timePeriod[1] = "Feb 2014 - April 2014";
      timePeriod[0] = "Aug 2012 - Nov 2013";

      locations[4] = "Duke";
      locations[3] = "Duke";
      locations[2] = "Duke";
      locations[1] = "CAS";
      locations[0] = "CAS";

      items.resize(5);
      items[4].push_back("Adopt probit regression to analyze relationship between age difference and divorce rate");
      items[4].push_back("Implement a Gibbs sampling to approximate the joint distribution of all parameters");
      items[4].push_back("Analysis confidence interval for parameters");

      items[3].push_back("Implement object perception by iterative closest point (ICP) in Python");
      items[3].push_back("Design grasps for robot grippers");
      items[3].push_back("Implement collision-free path of the robot arms in simulation in Python");

      items[2].push_back("Design a revised algorithm for metric learning method of large margin nearest neighbor (LMNN)");
      items[2].push_back("Implement a speed-up version of LMNN");
      items[2].push_back("Implement LMNN in robot motion planning in Matlab and C++");

      items[1].push_back("Develop the user interface on Android cellphone to enhance customer experience");
      items[1].push_back("Implement real-time signal analysis on Android cellphone");

      items[0].push_back("Propose an empirical mode decomposition (EMD) based algorithm to implement noise removal");
      items[0].push_back("Propose an EMD-based algorithm to implement the signal feature extraction");
      items[0].push_back("Adopt a fitting method to evaluate the baseline wander in real time");
      items[0].push_back("Publish two papers");
    }
    void printExperience(const int num = 5) {
      // yellow
      std::cout << CYAN;
      std::cout << "EXPERIENCE" << std::endl;
      std::cout << RESET;
      for (int i = num-1; i >= 0; i--) {
        std::cout << YELLOW;
        std::cout << exper[i] << ", " 
  		  << locations[i] << "    " 
  		  << timePeriod[i] << std::endl;
        std::cout << RESET;
        for (int item = 0; item < items[i].size(); item++) {
	  std::cout << " - " << items[i][item] << std::endl;
        }
        std::cout << std::endl;
      }
    }
    ~Experience() {}
  };

  class ExtraCurr {
  private:
    string title[4];
    string place[4];
    string time[4];
  public:
    ExtraCurr () {
      title[3] = "Academic writing instructor";
      title[2] = "Leader of Hip-hop dancing club";
      title[1] = "Autumn badminton competition";
      title[0] = "Secretary general of student union";

      place[3] = "New Oriental School, Beijing, China";
      place[2] = "CAS";
      place[1] = "CAS";
      place[0] = "WUT";

      time[3] = "Jan 2014 - July 2014";
      time[2] = "Oct 2012 - Oct 2013";
      time[1] = "Oct 2012";
      time[0] = "Oct 2007 - June 2008";
    }
    void printExtraCurr (const int num = 4) {
      std::cout << CYAN;
      std::cout << "EXTRACURRICULAR ACTIVITIES" << std::endl;
      std::cout << RESET;
      for (int i = num-1; i >= 0; i--) {
	std::cout << " - " 
		  << title[i] << ", " 
		  << place[i] << ", " <<  "    " 
		  << time[i] << std::endl;
      }
      std::cout << std::endl;
    }
    ~ExtraCurr() {}
  };

  School attendedSchool;
  Experience experience;
  Publication publications;
  ExtraCurr extracurricular;

public:
  PersonInfo() {
    name = "Xiao (Margaret) Tan";
    email = "Email: xiao.tan@duke.edu";
    language = "Programming language: C/C++, Java, Python, Matlab, R, Verilog";
  }
  void printPersonInfo() {
    std::cout << std::endl;
    std::cout << CYAN;
    std::cout << "INFOMATION" << std::endl;
    std::cout << RESET;
    std::cout << name << std::endl;
    std::cout << email << std::endl;
    std::cout << language << "\n" << std::endl;
  }
  void printEducation() {
    attendedSchool.printSchool(3);
  }
  void printExperience() {
    experience.printExperience();
  }
  void printPublications() {
    publications.printPublication(3);
  }
  void printExtras() {
    extracurricular.printExtraCurr(4);
  }
  ~PersonInfo() {}
};

#endif
