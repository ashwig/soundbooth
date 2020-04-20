#include <string>

std::string obscureData(std::string inputData) {
  size_t position = 0;

  std::string studentData = inputData;

  while (true) {
    // Find the location of the first space in the data. This should be the
    // separation of the first and last name.
    size_t firstSpace = studentData.find_first_of(' ', position);
    if (firstSpace == std::string::npos)
      break;
    position = studentData.find_first_of(' ', firstSpace + 1) + 1;

    // First and last name will give us 2 spaces before the social security
    // number and the SSN should be 11 characters long.
    studentData.replace(position, 11, "xxx-xx-xxxx");
    position += 10;

    // We then have 2 more spaces until the password
    position = studentData.find_first_of(' ', position + 1);
    position = studentData.find_first_of(' ', position + 1);

    // Replace the characters we find until the end with 'x'
    position += 1;
    while (position < studentData.length()) {
      studentData.replace(position, 1, "x");
      position += 1;
      if (position == std::string::npos)
        break;
    }
  }

  if (position == std::string::npos)
    return studentData;

  return studentData;
}