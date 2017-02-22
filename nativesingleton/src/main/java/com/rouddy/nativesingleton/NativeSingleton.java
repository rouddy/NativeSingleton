package com.rouddy.nativesingleton;

import android.util.Log;

/**
 * Created by yoojaehong on 2016. 8. 11..
 */

public abstract class NativeSingleton {

	static {
		System.loadLibrary("singleton");
	}

	public static NativeSingleton getInstance(Class<? extends NativeSingleton> clazz) {
		String strClass = clazz.getName();
		NativeSingleton instance = getSingleton(strClass);
		if (instance == null) {
			try {
				instance = clazz.newInstance();
				setSingleton(strClass, instance);
			} catch (InstantiationException e) {
				throw new RuntimeException("cannot create instance", e);
			} catch (IllegalAccessException e) {
				throw new RuntimeException("cannot create instance", e);
			}
		}

		return instance;
	}

	private native static NativeSingleton getSingleton(String clsName);
	private native static void setSingleton(String clsName, NativeSingleton object);
}
