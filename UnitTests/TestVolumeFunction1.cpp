#include "stdafx.h"
#include "PaintEstimator.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace UnitTests
{
	[TestClass]
	public ref class TestVolumeFunction1
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes

		#pragma endregion 

		[TestMethod]
		void TestWallArea()
		{
            float fWidth =  1.2f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual((double)workerClass.CalculateWallArea(), 13.2, 0.01, "Should be equal");
		};
        [TestMethod]
		void TestFloorArea()
		{
            float fWidth =  1.2f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual((double)workerClass.CalculateFloorArea(), 3.84, 0.01, "Should be equal");
		};
        [TestMethod]
		void TestVolume()
		{
            float fWidth =  1.2f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual((double)workerClass.CalculateVolume(), 5.76, 0.01, "Should be equal");
		};
        [TestMethod]
		void TestPaintReq()
		{
            float fWidth =  1.2f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            float fWallArea = workerClass.CalculateWallArea(); 
            Assert::AreEqual((double)workerClass.CalculatePaintReq(fWallArea), 10.56, 0.01, "Should be equal");
		};
        [TestMethod]
		void TestZeroWidth()
		{
            float fWidth =  0.0f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual(workerClass.ValidateMeasurements(), false, "Should be false");
		};
        [TestMethod]
		void TestFltMaxLength()
		{
            float fWidth =  1.2f;
            float fLength = FLT_MAX;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual(workerClass.ValidateMeasurements(), false, "Should be false");
		};
	};
}
