#ifndef __FRAMEWORK_CNN_MATH_VECTOR_H__
#define __FRAMEWORK_CNN_MATH_VECTOR_H__

namespace lzw{
	class Vector
	{
	private:
		/* data */
        int x;
        int y;
	public:
		Vector(/* args */);
		Vector(int x,int y){this->x=x;this->y=y;};
		~Vector();

        int getX(){return this->x;};
        int getY(){return this->y;};
        void getX(int x){this->x=x;};
        void getY(int y){this->x=y;};
	};

};

#endif // !__FRAMEWORK_CNN_MATH_VECTOR_H__ 