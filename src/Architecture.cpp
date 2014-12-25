namespace dpd
{
class IPlay
{
	IPlay(){}
	~IPlay(){}
	virtual void play() = 0 ;
	virtual void stop() = 0 ;
	virtual void forward() = 0 ;
	virtual void backward() = 0 ;
}

class Component : IPlay
{
	Component(){}
	~Component(){}
	virtual void play(){}
	virtual void stop(){} ;
	virtual void forward(){} ;
	virtual void backward(){} ;
}

class TextComponent : Component
{
	// show text when display picture
	String text ;
	Time start_time, stop_time ;
	TextComponent(String str, Time t1, Time t2) : str(text), start_time(t1), stop_time(t2){}
	~TextComponent(){} 
	
	void play()
	{
		// 計時
		Time t = current_tiem ;
		while(true)
		{
			if (t == start_time) 
				open thread to draw text ;
			else if (t == end_time)
				stop all and break
		}
	}
	
	void stop()
	{
		
	}
}


// 特效種類
enum EffectType
{
	NEED_SHOW_PICTURE = 0,
	NO_NEED_SHOW_PICTURE = 1,
	Something...etc
}

class Effective
{
	BaseView view ;
	EffectType type ;
	explicit Effective(){} 
	virtual EffectType getType(){} = 0 ;
	virtual void pre() = 0 ;
	virtual void mid() = 0 ; // it's complex 
	virtual void post() = 0 ;
	using ttt::aaa:ccc::sss::hello
	
	hello a ;
}

class RoomInOut : Effective
{
	RoomInOut(B)
	
	RoomInOut(A, B, C)  //1, 3, 1  or  1, 0, 1
}

class NonEffective : Effective
{
	NonEffective() ;
}

class PictureComponent : Component
{
	Effective effective ;
	PictureComponent() : effective(0) {}
	PictureComponent() : effective(new NonEffective()) {}
	PictureComponent(Effective e): effective(e) {}
	~PictureComponent(){}
	

	void play()
	{
		View a =new View ;
		a.height= 100
		a.wight = 100 
	
		// generate picture view and ready it
		if (!effective)
			just only show picture+++
		else
		{
			effective.pre(a) ;
			// mid is hard to implement
			if (effective.getType == NEED_SHOW_PICTURE)
				show picture ;
			else
				dont show picture !! ;
			effective.post() ;
			
			effective.pre() ;
			effective.mid() ;
			effective.post() ;
		}
		a.kill
	}
	
	void stop(){}
}


class FrameObj : IPlay
{

	FrameObj(duration_time, Something) : IPlay{}
	~FrameObj(){}

	vector<Thread> t ;
	void add_item(Component m){ items.push_back(m) ;}
	
	void play(){}

	void stop() {}
	
	
	vector<Component> & items()
	{
		return this->items();
	}
}
}

class Controller
{
	vector<FrameObj> obj ;
	vector<Thread> t ;
	
    void play()
	{
		for (iter in each obj)
		{
			// iter->play() ;

			vector<Component> & items = iter->items();
			
			for (item in items) {
				if thread obj != null 
					...
				
				else
				{
					for iter in items
						Thread thread = new Thread(iter->play()) ;
						t.push_back(thread)
						thread->run();
						// open thread to start iter->play() ;
						
				}
			}
			
			check items thread is finish
			while (true)
				if yes 
					break ;
				else
					wait for iter thread's end
		}
	}
	
	void stop()
	{
		for iter in t
			iter->pause() ;
	}

};

main()
{
	vector<FrameObj> obj ;
	FrameObj frame = new FrameObj( 5 sec, Something ) ;
	
	// we can use decorate pattern or another way to do it.
	frame.add_item(new TextComponent) ;
	frame.add_item(new RoomInPictureComponent())) ;
	
	obj.push_back(frame) ;
	
	for (iter in each frames)
	{
		iter->play() ;

	}
	
	pass_to_player(global_setting, obj) ;
}
