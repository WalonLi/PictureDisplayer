/**
    Provide by Walon Li, YJ Fang

    File Controller.tcc
**/

template <typename Iterator>
void pdr::Controller::addFrame(Iterator first, Iterator last)
{
    this->frames.insert(this->frames.end(), first, last);
}